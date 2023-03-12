
int CMS_dataFinal(CMS_ContentInfo *cms,BIO *bio)

{
  int iVar1;
  BIO *bp;
  long len;
  ASN1_STRING **ppAVar2;
  void *local_1c;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x19) {
LAB_000e4e98:
    ppAVar2 = (ASN1_STRING **)(*(int *)(*(int *)(cms + 4) + 8) + 4);
LAB_000e4e9e:
    if (ppAVar2 == (ASN1_STRING **)0x0) {
      return 0;
    }
  }
  else {
    if (0x19 < iVar1) {
      if (iVar1 == 0xcd) {
        ppAVar2 = (ASN1_STRING **)(*(int *)(*(int *)(cms + 4) + 0x14) + 4);
      }
      else if (iVar1 == 0x312) {
        ppAVar2 = (ASN1_STRING **)(*(int *)(*(int *)(cms + 4) + 0xc) + 4);
      }
      else {
        if (iVar1 != 0x1a) goto LAB_000e4e7a;
        ppAVar2 = (ASN1_STRING **)(*(int *)(*(int *)(cms + 4) + 4) + 8);
      }
      goto LAB_000e4e9e;
    }
    if (iVar1 == 0x16) goto LAB_000e4e98;
    if (iVar1 == 0x17) {
      ppAVar2 = (ASN1_STRING **)(*(int *)(*(int *)(cms + 4) + 0xc) + 8);
      goto LAB_000e4e9e;
    }
    if (iVar1 == 0x15) {
      ppAVar2 = (ASN1_STRING **)(cms + 4);
    }
    else {
LAB_000e4e7a:
      if (**(int **)(cms + 4) != 4) {
        ERR_put_error(0x2e,0x81,0x98,"cms_lib.c",0xee);
        return 0;
      }
      ppAVar2 = (ASN1_STRING **)(*(int **)(cms + 4) + 1);
    }
  }
  if ((*ppAVar2 != (ASN1_STRING *)0x0) && ((*ppAVar2)->flags << 0x1a < 0)) {
    bp = BIO_find_type(bio,0x401);
    if (bp == (BIO *)0x0) {
      ERR_put_error(0x2e,0x6e,0x69,"cms_lib.c",0xac);
      return 0;
    }
    len = BIO_ctrl(bp,3,0,&local_1c);
    BIO_set_flags(bp,0x200);
    BIO_ctrl(bp,0x82,0,(void *)0x0);
    ASN1_STRING_set0(*ppAVar2,local_1c,len);
    (*ppAVar2)->flags = (*ppAVar2)->flags & 0xffffffdf;
  }
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 != 0x17) {
    if (iVar1 < 0x18) {
      if (iVar1 != 0x15) {
        if (iVar1 == 0x16) {
          iVar1 = cms_SignedData_final(cms,bio);
          return iVar1;
        }
        goto LAB_000e4ed8;
      }
    }
    else if ((iVar1 != 0x1a) && (iVar1 != 0x312)) {
      if (iVar1 == 0x19) {
        iVar1 = cms_DigestedData_do_final(cms,bio,0);
        return iVar1;
      }
LAB_000e4ed8:
      ERR_put_error(0x2e,0x6e,0x9c,"cms_lib.c",200);
      return 0;
    }
  }
  return 1;
}

