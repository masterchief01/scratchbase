#include "catch.hpp"
#include "scratchbase/scratchbase.h"

TEST_CASE("Store and retrieve a value","[setKeyValue,getKeyValue]") {

  // Story:-
  //   [Who]   As a database user
  //   [What]  I need to store and retrieve a value with a simple name
  //   [Value] So I can persist data for later use
  SECTION("Basic set and get") {
    std::string dbname("myemptydb");
    std::unique_ptr<scratchbase::IDatabase> db(scratchbase::ScratchBase::createEmptyDB(dbname));

    // We know we have been successful when:-
    // 1. The retrieved value is the same as the stored value
    std::string key("simplestring");
    std::string value("Some highly valuable value");
    db->setKeyValue(key,value);
    REQUIRE(value == db->getKeyValue(key));

    db->destroy();
  }

  //   [Who]   As a database user
  //   [What]  I want to be able to logically segment my data
  //   [Value] To make storage, querying, retrieval, backups and restores easier and quicker
  SECTION("Bucketed set and get") {

  }


}