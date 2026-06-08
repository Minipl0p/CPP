
#include "../includes/MutantStack.hpp"
#include <iostream>

#include <string>
#include <list>

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define CYAN  "\033[36m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

// ─── Helper ───────────────────────────────────────────────────────────────────

template <typename T>
void check(const std::string &label, T got, T expected)
{
    bool ok = (got == expected);
    std::cout << (ok ? GREEN "[OK] " : RED "[KO] ")
              << RESET << label
              << " | expected: " << expected
              << " | got: " << got << "\n";
}

void section(const std::string &title)
{
    std::cout << "\n" << CYAN
              << "══════════════════════════════════════\n"
              << "  " << title << "\n"
              << "══════════════════════════════════════"
              << RESET << "\n";
}

// ─── Tests ────────────────────────────────────────────────────────────────────

void test_basic_stack()
{
    section("1 – Basic stack operations");

    MutantStack<int> ms;

    check("empty() on new stack",    ms.empty(), true);
    check("size()  on new stack",    (int)ms.size(), 0);

    ms.push(5);
    ms.push(17);
    check("top() after push(5),push(17)", ms.top(), 17);

    ms.pop();
    check("top() after pop()",       ms.top(), 5);
    check("size() after pop()",      (int)ms.size(), 1);

    ms.push(3);
    ms.push(5);
    ms.push(737);
    ms.push(0);
    check("size() after 4 more pushes", (int)ms.size(), 5);
    check("top()  is 0",                ms.top(), 0);
    check("empty() is false",           ms.empty(), false);
}

void test_forward_iteration()
{
    section("2 – Forward iterator");

    MutantStack<int> ms;
    ms.push(1);
    ms.push(2);
    ms.push(3);
    ms.push(4);
    ms.push(5);

    // Stack stores bottom→top, iterators go bottom→top too
    int expected[] = {1, 2, 3, 4, 5};
    int idx = 0;
    std::string allOk = "yes";

    MutantStack<int>::iterator it  = ms.begin();
    MutantStack<int>::iterator ite = ms.end();
    while (it != ite)
    {
        if (*it != expected[idx]) allOk = "no";
        ++it; ++idx;
    }
    check("forward traversal order correct", allOk, std::string("yes"));
    check("exact count of elements visited", idx, 5);

    // pre/post increment & decrement
    it = ms.begin();
    ++it;
    check("pre-increment  (*it == 2)", *it, 2);
    --it;
    check("pre-decrement  (*it == 1)", *it, 1);
    it++;
    check("post-increment (*it == 2)", *it, 2);
    it--;
    check("post-decrement (*it == 1)", *it, 1);
}

void test_const_iterators()
{
    section("4 – Const iterators");

    MutantStack<int> ms;
    ms.push(7);
    ms.push(14);
    ms.push(21);

    const MutantStack<int> &cms = ms;

    int sum = 0;
    MutantStack<int>::const_iterator cit  = cms.begin();
    MutantStack<int>::const_iterator cite = cms.end();
    while (cit != cite) { sum += *cit; ++cit; }
    check("const_iterator sum (7+14+21)", sum, 42);
}

void test_copy_and_assign()
{
    section("5 – Copy constructor & assignment");

    MutantStack<int> original;
    original.push(100);
    original.push(200);
    original.push(300);

    // copy ctor
    MutantStack<int> copy(original);
    check("copy: size()",  (int)copy.size(), 3);
    check("copy: top()",   copy.top(), 300);
    copy.pop();
    // original must be untouched
    check("original size after modifying copy", (int)original.size(), 3);
    check("original top  after modifying copy", original.top(), 300);

    // assignment
    MutantStack<int> assigned;
    assigned.push(999);
    assigned = original;
    check("assigned: size()", (int)assigned.size(), 3);
    check("assigned: top()",  assigned.top(), 300);

    // copy via std::stack ctor (subject requirement)
    std::stack<int> plain(original);
    check("std::stack copy: size()", (int)plain.size(), 3);
    check("std::stack copy: top()",  plain.top(), 300);
}

void test_equivalence_with_list()
{
    section("6 – MutantStack vs std::list (same sequence)");

    MutantStack<int> ms;
    std::list<int>   lst;

    int vals[] = {5, 1, 42, 8, 17, 0, 737};
    for (int i = 0; i < 7; ++i) { ms.push(vals[i]); lst.push_back(vals[i]); }

    std::list<int>::iterator  li  = lst.begin();
    MutantStack<int>::iterator mi = ms.begin();
    std::string same = "yes";
    while (li != lst.end() && mi != ms.end())
    {
        if (*li != *mi) same = "no";
        ++li; ++mi;
    }
    if (li != lst.end() || mi != ms.end()) same = "no";
    check("iteration matches std::list order", same, std::string("yes"));
}

void test_string_stack()
{
    section("7 – Template: MutantStack<std::string>");

    MutantStack<std::string> ms;
    ms.push("hello");
    ms.push("world");
    ms.push("42");

    check("top()",  ms.top(), std::string("42"));
    check("size()", (int)ms.size(), 3);

    std::string concat;
    MutantStack<std::string>::iterator it  = ms.begin();
    MutantStack<std::string>::iterator ite = ms.end();
    while (it != ite) { concat += *it; ++it; }
    check("concat bottom→top", concat, std::string("helloworld42"));
}

void test_edge_cases()
{
    section("8 – Edge cases");

    // Single element
    MutantStack<int> ms;
    ms.push(99);
    check("begin == end - 1 (size 1)", *ms.begin(), 99);
    check("size 1: begin+1 == end",
          ms.begin() + 1 == ms.end(), true);

    // Empty after pop
    ms.pop();
    check("empty() after last pop", ms.empty(), true);
    check("begin() == end() when empty",
          ms.begin() == ms.end(), true);

    // Many pushes then many pops
    for (int i = 0; i < 1000; ++i) ms.push(i);
    check("size after 1000 pushes", (int)ms.size(), 1000);
    check("top  after 1000 pushes", ms.top(), 999);
    for (int i = 0; i < 1000; ++i) ms.pop();
    check("empty after 1000 pops",  ms.empty(), true);
}

// ─── Original subject main (kept intact, output shown) ────────────────────────

void test_subject_main()
{
    section("9 – Original subject main (reference output)");

    std::cout << YELLOW
              << "Expected:\n"
              << "  17\n"
              << "  1\n"
              << "  5\n"
              << "  3\n"
              << "  5\n"
              << "  737\n"
              << "  0\n"
              << RESET;

    std::cout << "Got:\n";

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "  " << mstack.top() << "\n";   // 17
    mstack.pop();
    std::cout << "  " << mstack.size() << "\n";  // 1
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it  = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it; --it;
    while (it != ite) { std::cout << "  " << *it << "\n"; ++it; }

    std::stack<int> s(mstack);
    (void)s;
}

// ─── Entry point ──────────────────────────────────────────────────────────────

int main()
{
    test_basic_stack();
    test_forward_iteration();
    test_const_iterators();
    test_copy_and_assign();
    test_equivalence_with_list();
    test_string_stack();
    test_edge_cases();
    test_subject_main();

    std::cout << "\n";
    return 0;
}
