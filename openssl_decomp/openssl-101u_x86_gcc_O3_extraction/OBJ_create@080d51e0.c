
int OBJ_create(char *oid,char *sn,char *ln)

{
  int iVar1;
  uchar *out;
  int len;
  int iVar2;
  ASN1_OBJECT *obj;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = a2d_ASN1_OBJECT((uchar *)0x0,0,oid,-1);
  if (0 < iVar1) {
    out = (uchar *)CRYPTO_malloc(iVar1,"obj_dat.c",0x312);
    if (out == (uchar *)0x0) {
      ERR_put_error(8,100,0x41,"obj_dat.c",0x313);
    }
    else {
      obj = (ASN1_OBJECT *)0x0;
      len = a2d_ASN1_OBJECT(out,iVar1,oid,-1);
      iVar1 = new_nid;
      iVar2 = 0;
      if (len != 0) {
        new_nid = new_nid + 1;
        obj = ASN1_OBJECT_create(iVar1,out,len,sn,ln);
        iVar2 = iVar3;
        if (obj != (ASN1_OBJECT *)0x0) {
          iVar2 = OBJ_add_object(obj);
        }
      }
      ASN1_OBJECT_free(obj);
      CRYPTO_free(out);
      iVar3 = iVar2;
    }
  }
  return iVar3;
}

