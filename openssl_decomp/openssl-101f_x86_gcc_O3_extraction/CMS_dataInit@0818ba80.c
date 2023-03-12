
BIO * CMS_dataInit(CMS_ContentInfo *cms,BIO *icont)

{
  int *piVar1;
  int iVar2;
  BIO *pBVar3;
  BIO *b;
  BIO *pBVar4;
  BIO_METHOD *type;
  int **ppiVar5;
  int line;
  
  pBVar4 = icont;
  if (icont != (BIO *)0x0) {
LAB_0818ba95:
    iVar2 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
    switch(iVar2) {
    case 0x15:
      return pBVar4;
    case 0x16:
      b = (BIO *)cms_SignedData_init_bio(cms);
      break;
    case 0x17:
      b = (BIO *)cms_EnvelopedData_init_bio(cms);
      break;
    default:
      line = 0x91;
      iVar2 = 0x9c;
      goto LAB_0818bb42;
    case 0x19:
      b = (BIO *)cms_DigestedData_init_bio(cms);
      break;
    case 0x1a:
      b = (BIO *)cms_EncryptedData_init_bio(cms);
    }
    if (b == (BIO *)0x0) {
      pBVar3 = (BIO *)0x0;
      if (icont == (BIO *)0x0) {
        BIO_free(pBVar4);
        pBVar3 = b;
      }
      return pBVar3;
    }
    pBVar4 = BIO_push(b,pBVar4);
    return pBVar4;
  }
  iVar2 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar2 == 0x19) {
LAB_0818bc28:
    ppiVar5 = (int **)(*(int *)(*(int *)(cms + 4) + 8) + 4);
LAB_0818bc00:
    if (ppiVar5 != (int **)0x0) {
LAB_0818bba0:
      piVar1 = *ppiVar5;
      if (piVar1 == (int *)0x0) {
        type = BIO_s_null();
LAB_0818bc15:
        pBVar4 = BIO_new(type);
      }
      else {
        if (piVar1[3] == 0x20) {
          type = BIO_s_mem();
          goto LAB_0818bc15;
        }
        pBVar4 = BIO_new_mem_buf((void *)piVar1[2],*piVar1);
      }
      if (pBVar4 != (BIO *)0x0) goto LAB_0818ba95;
    }
  }
  else {
    if (0x19 < iVar2) {
      if (iVar2 == 0xcd) {
        ppiVar5 = (int **)(*(int *)(*(int *)(cms + 4) + 0x14) + 4);
      }
      else if (iVar2 == 0x312) {
        ppiVar5 = (int **)(*(int *)(*(int *)(cms + 4) + 0xc) + 4);
      }
      else {
        if (iVar2 != 0x1a) goto LAB_0818bb8b;
        ppiVar5 = (int **)(*(int *)(*(int *)(cms + 4) + 4) + 8);
      }
      goto LAB_0818bc00;
    }
    if (iVar2 == 0x16) goto LAB_0818bc28;
    if (iVar2 == 0x17) {
      ppiVar5 = (int **)(*(int *)(*(int *)(cms + 4) + 0xc) + 8);
      goto LAB_0818bc00;
    }
    if (iVar2 == 0x15) {
      ppiVar5 = (int **)(cms + 4);
      goto LAB_0818bba0;
    }
LAB_0818bb8b:
    if (**(int **)(cms + 4) == 4) {
      ppiVar5 = (int **)(*(int **)(cms + 4) + 1);
      goto LAB_0818bba0;
    }
    ERR_put_error(0x2e,0x81,0x98,"cms_lib.c",0xee);
  }
  line = 0x72;
  iVar2 = 0x7f;
LAB_0818bb42:
  ERR_put_error(0x2e,0x6f,iVar2,"cms_lib.c",line);
  return (BIO *)0x0;
}

