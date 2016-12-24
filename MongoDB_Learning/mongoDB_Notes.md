## MongoDB
>A record in MongoDB is a document, which is a data structure composed of field and value pairs.

**Advantages of MongoDB**

- Documents (i.e. objects) correspond to native data types in many programming languages.
- Embedded documents and arrays reduce need for expensive joins.
- Dynamic schema supports fluent polymorphism.

#### Databases

In MongoDB, databases hold collections of documents.

If a database does not exist, MongoDB creates the database when you first store data for that database. 

```use myNewDB```

```db.myNewCollection.insert({x: 1})```

The insert() operation creates both the databases ```myNewDB``` and collection ```myNewCollection```.

#### Collections

MongoDB stored documents in collections.
You cannot delete documents from a capped collection. To remove all documents from a collection, use the drop() method to drop the collection and recreate the capped collection.

#### Documents

MongoDB stores data records as BSON documents. BSON is a binary representation of JSON documents.
