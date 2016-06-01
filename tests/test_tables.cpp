#include <gtest.h>
#include "hash.h"
#include "sort.h"
#include "tree.h"

TEST(hash_table, can_create_table)
{
	ASSERT_NO_THROW(hashtable table);
}

TEST(hash_table, can_add)
{
	hashtable table;
	ASSERT_NO_THROW(table.insert("a", 1));
}

TEST(hash_table, can_search)
{
	hashtable table;
	table.insert("d", 4);
	table.insert("a", 1);
	table.insert("b", 2);
	EXPECT_EQ(table.search("b")->getkey(), "b");
}

TEST(hash_table, can_delete)
{
	hashtable table;
	table.insert("d", 4);
	table.insert("a", 1);
	table.insert("b", 2);
	ASSERT_NO_THROW(table.del("b"));
}

TEST(sort_table, can_create_table)
{
	ASSERT_NO_THROW(sorttable table);
}

TEST(sort_table, can_add)
{
	sorttable table;
	ASSERT_NO_THROW(table.insert("a", 1));
}

TEST(sort_table, can_search)
{
	sorttable table;
	table.insert("d", 4);
	table.insert("a", 1);
	table.insert("b", 2);
	EXPECT_EQ(table.table[table.search("b")].k,"b");
}

TEST(sort_table, can_delete)
{
	sorttable table;
	table.insert("d", 4);
	table.insert("a", 1);
	table.insert("b", 2);
	ASSERT_NO_THROW(table.del("b"));
}

TEST(bintree, can_create)
{
	ASSERT_NO_THROW(bintree bin);
}

TEST(bintree, can_add)
{
	bintree bin;
	bin.root = bin.create(bin.root, bin.root, "a");
	EXPECT_EQ(bin.root->val, "a");
}

TEST(bintree, can_search)
{
	bintree bin;
	bin.root = bin.create(bin.root, bin.root, "a");
	EXPECT_EQ(bin.search("a", bin.root)->val, "a");
}

TEST(bintree, can_delete_a)
{
	bintree bin;
	bin.root = bin.create(bin.root, bin.root, "d");
	bin.root = bin.create(bin.root, bin.root, "b");
	bin.root = bin.create(bin.root, bin.root, "e");
	bin.root = bin.create(bin.root, bin.root, "a");
	bin.root = bin.create(bin.root, bin.root, "c");
	bin.root = bin.create(bin.root, bin.root, "f");
	ASSERT_NO_THROW(bin.remove("a", bin.root));
}
TEST(bintree, can_delete_b)
{
	bintree bin;
	bin.root = bin.create(bin.root, bin.root, "d");
	bin.root = bin.create(bin.root, bin.root, "b");
	bin.root = bin.create(bin.root, bin.root, "e");
	bin.root = bin.create(bin.root, bin.root, "a");
	bin.root = bin.create(bin.root, bin.root, "c");
	bin.root = bin.create(bin.root, bin.root, "f");
	ASSERT_NO_THROW(bin.remove("b", bin.root));
}
TEST(bintree, can_delete_c)
{
	bintree bin;
	bin.root = bin.create(bin.root, bin.root, "d");
	bin.root = bin.create(bin.root, bin.root, "b");
	bin.root = bin.create(bin.root, bin.root, "e");
	bin.root = bin.create(bin.root, bin.root, "a");
	bin.root = bin.create(bin.root, bin.root, "c");
	bin.root = bin.create(bin.root, bin.root, "f");
	ASSERT_NO_THROW(bin.remove("c", bin.root));
}
TEST(bintree, can_delete_d)
{
	bintree bin;
	bin.root = bin.create(bin.root, bin.root, "d");
	bin.root = bin.create(bin.root, bin.root, "b");
	bin.root = bin.create(bin.root, bin.root, "e");
	bin.root = bin.create(bin.root, bin.root, "a");
	bin.root = bin.create(bin.root, bin.root, "c");
	bin.root = bin.create(bin.root, bin.root, "f");
	ASSERT_NO_THROW(bin.remove("d", bin.root));
}
TEST(bintree, can_delete_e)
{
	bintree bin;
	bin.root = bin.create(bin.root, bin.root, "d");
	bin.root = bin.create(bin.root, bin.root, "b");
	bin.root = bin.create(bin.root, bin.root, "e");
	bin.root = bin.create(bin.root, bin.root, "a");
	bin.root = bin.create(bin.root, bin.root, "c");
	bin.root = bin.create(bin.root, bin.root, "f");
	ASSERT_NO_THROW(bin.remove("e", bin.root));
}
TEST(bintree, can_delete_f)
{
	bintree bin;
	bin.root = bin.create(bin.root, bin.root, "d");
	bin.root = bin.create(bin.root, bin.root, "b");
	bin.root = bin.create(bin.root, bin.root, "e");
	bin.root = bin.create(bin.root, bin.root, "a");
	bin.root = bin.create(bin.root, bin.root, "c");
	bin.root = bin.create(bin.root, bin.root, "f");
	ASSERT_NO_THROW(bin.remove("f", bin.root));
}