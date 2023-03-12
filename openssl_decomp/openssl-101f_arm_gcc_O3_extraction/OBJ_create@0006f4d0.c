
int OBJ_create(char *oid,char *sn,char *ln)

{
  int iVar1;
  ASN1_OBJECT *out;
  ASN1_OBJECT *obj;
  ASN1_OBJECT *pAVar2;
  
  iVar1 = a2d_ASN1_OBJECT((uchar *)0x0,0,oid,-1);
  if (iVar1 < 1) {
    out = (ASN1_OBJECT *)0x0;
  }
  else {
    out = (ASN1_OBJECT *)CRYPTO_malloc(iVar1,"obj_dat.c",0x319);
    if (out == (ASN1_OBJECT *)0x0) {
      ERR_put_error(8,100,0x41,"obj_dat.c",0x31b);
    }
    else {
      obj = (ASN1_OBJECT *)a2d_ASN1_OBJECT((uchar *)out,iVar1,oid,-1);
      iVar1 = new_nid;
      pAVar2 = obj;
      if (obj != (ASN1_OBJECT *)0x0) {
        new_nid = new_nid + 1;
        obj = ASN1_OBJECT_create(iVar1,(uchar *)out,(int)obj,sn,ln);
        pAVar2 = obj;
        if (obj != (ASN1_OBJECT *)0x0) {
          pAVar2 = (ASN1_OBJECT *)OBJ_add_object(obj);
        }
      }
      ASN1_OBJECT_free(obj);
      CRYPTO_free(out);
      out = pAVar2;
    }
  }
  return (int)out;
}

