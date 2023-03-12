
OPENSSL_STRING * TXT_DB_get_by_index(TXT_DB *db,int idx,OPENSSL_STRING *value)

{
  OPENSSL_STRING *ppcVar1;
  undefined4 in_a3;
  
  if (db->num_fields <= idx) {
    db->error = 3;
    return (OPENSSL_STRING *)0x0;
  }
  if (db->index[idx] != (lhash_st_OPENSSL_STRING *)0x0) {
    ppcVar1 = (OPENSSL_STRING *)
              (*(code *)PTR_lh_retrieve_006a84b0)(db->index[idx],value,value,in_a3,&_gp);
    db->error = 0;
    return ppcVar1;
  }
  db->error = 4;
  return (OPENSSL_STRING *)0x0;
}

