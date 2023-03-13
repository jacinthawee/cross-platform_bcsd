
int X509_NAME_add_entry_by_NID
              (X509_NAME *name,int nid,int type,uchar *bytes,int len,int loc,int set)

{
  ASN1_OBJECT *o;
  X509_NAME_ENTRY *ne;
  ASN1_OBJECT *pAVar1;
  int iVar2;
  
  o = OBJ_nid2obj(nid);
  if (o == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0xb,0x72,0x6d,"x509name.c",0x139);
  }
  else {
    ne = X509_NAME_ENTRY_new();
    if (ne != (X509_NAME_ENTRY *)0x0) {
      ASN1_OBJECT_free(ne->object);
      pAVar1 = OBJ_dup(o);
      ne->object = pAVar1;
      if (pAVar1 != (ASN1_OBJECT *)0x0) {
        iVar2 = X509_NAME_ENTRY_set_data(ne,type,bytes,len);
        if (iVar2 != 0) {
          ASN1_OBJECT_free(o);
          iVar2 = X509_NAME_add_entry(name,ne,loc,set);
          X509_NAME_ENTRY_free(ne);
          return iVar2;
        }
      }
      X509_NAME_ENTRY_free(ne);
    }
    ASN1_OBJECT_free(o);
  }
  return 0;
}

