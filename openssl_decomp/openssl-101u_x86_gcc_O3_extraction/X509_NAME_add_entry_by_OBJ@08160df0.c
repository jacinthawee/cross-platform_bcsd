
int X509_NAME_add_entry_by_OBJ
              (X509_NAME *name,ASN1_OBJECT *obj,int type,uchar *bytes,int len,int loc,int set)

{
  X509_NAME_ENTRY *a;
  ASN1_OBJECT *pAVar1;
  int iVar2;
  
  a = X509_NAME_ENTRY_new();
  if (a != (X509_NAME_ENTRY *)0x0) {
    if (obj == (ASN1_OBJECT *)0x0) {
      ERR_put_error(0xb,0x73,0x43,"x509name.c",0x160);
      X509_NAME_ENTRY_free(a);
    }
    else {
      ASN1_OBJECT_free(a->object);
      pAVar1 = OBJ_dup(obj);
      a->object = pAVar1;
      if (pAVar1 != (ASN1_OBJECT *)0x0) {
        iVar2 = X509_NAME_ENTRY_set_data(a,type,bytes,len);
        if (iVar2 != 0) {
          iVar2 = X509_NAME_add_entry(name,a,loc,set);
          X509_NAME_ENTRY_free(a);
          return iVar2;
        }
      }
      X509_NAME_ENTRY_free(a);
    }
  }
  return 0;
}

