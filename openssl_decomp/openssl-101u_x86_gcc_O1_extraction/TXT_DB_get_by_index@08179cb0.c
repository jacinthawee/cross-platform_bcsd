
OPENSSL_STRING * TXT_DB_get_by_index(TXT_DB *db,int idx,OPENSSL_STRING *value)

{
  _LHASH *lh;
  
  if (db->num_fields != idx && idx <= db->num_fields) {
    lh = (_LHASH *)db->index[idx];
    if (lh == (_LHASH *)0x0) {
      db->error = 4;
    }
    else {
      lh = (_LHASH *)lh_retrieve(lh,value);
      db->error = 0;
    }
    return (OPENSSL_STRING *)lh;
  }
  db->error = 3;
  return (OPENSSL_STRING *)0x0;
}

