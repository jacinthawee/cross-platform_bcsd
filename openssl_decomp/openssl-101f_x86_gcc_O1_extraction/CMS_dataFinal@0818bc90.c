
int CMS_dataFinal(CMS_ContentInfo *cms,BIO *bio)

{
  int iVar1;
  BIO *bp;
  long len;
  ASN1_STRING **ppAVar2;
  int in_GS_OFFSET;
  int line;
  void *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x19) {
LAB_0818bd10:
    ppAVar2 = (ASN1_STRING **)(*(int *)(*(int *)(cms + 4) + 8) + 4);
LAB_0818bd19:
    if (ppAVar2 != (ASN1_STRING **)0x0) goto LAB_0818bd21;
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
        if (iVar1 != 0x1a) {
LAB_0818bcdb:
          if (**(int **)(cms + 4) != 4) {
            ERR_put_error(0x2e,0x81,0x98,"cms_lib.c",0xee);
            iVar1 = 0;
            goto LAB_0818bd71;
          }
          ppAVar2 = (ASN1_STRING **)(*(int **)(cms + 4) + 1);
          goto LAB_0818bd21;
        }
        ppAVar2 = (ASN1_STRING **)(*(int *)(*(int *)(cms + 4) + 4) + 8);
      }
      goto LAB_0818bd19;
    }
    if (iVar1 == 0x16) goto LAB_0818bd10;
    if (iVar1 == 0x17) {
      ppAVar2 = (ASN1_STRING **)(*(int *)(*(int *)(cms + 4) + 0xc) + 8);
      goto LAB_0818bd19;
    }
    if (iVar1 != 0x15) goto LAB_0818bcdb;
    ppAVar2 = (ASN1_STRING **)(cms + 4);
LAB_0818bd21:
    if ((*ppAVar2 == (ASN1_STRING *)0x0) || ((*(byte *)&(*ppAVar2)->flags & 0x20) == 0)) {
LAB_0818bd31:
      iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
      if (iVar1 == 0x17) {
LAB_0818be48:
        iVar1 = 1;
        goto LAB_0818bd71;
      }
      if (iVar1 < 0x18) {
        if (iVar1 == 0x15) goto LAB_0818be48;
        if (iVar1 == 0x16) {
          iVar1 = cms_SignedData_final(cms,bio);
          goto LAB_0818bd71;
        }
      }
      else {
        if ((iVar1 == 0x1a) || (iVar1 == 0x312)) goto LAB_0818be48;
        if (iVar1 == 0x19) {
          iVar1 = cms_DigestedData_do_final(cms,bio,0);
          goto LAB_0818bd71;
        }
      }
      line = 200;
      iVar1 = 0x9c;
    }
    else {
      bp = BIO_find_type(bio,0x401);
      if (bp != (BIO *)0x0) {
        len = BIO_ctrl(bp,3,0,&local_24);
        BIO_set_flags(bp,0x200);
        BIO_ctrl(bp,0x82,0,(void *)0x0);
        ASN1_STRING_set0(*ppAVar2,local_24,len);
        (*ppAVar2)->flags = (*ppAVar2)->flags & 0xffffffdf;
        goto LAB_0818bd31;
      }
      line = 0xac;
      iVar1 = 0x69;
    }
    ERR_put_error(0x2e,0x6e,iVar1,"cms_lib.c",line);
  }
  iVar1 = 0;
LAB_0818bd71:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

