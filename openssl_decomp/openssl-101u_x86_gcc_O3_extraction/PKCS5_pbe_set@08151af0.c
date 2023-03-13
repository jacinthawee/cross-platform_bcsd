
X509_ALGOR * PKCS5_pbe_set(int alg,int iter,uchar *salt,int saltlen)

{
  X509_ALGOR *alg_00;
  ASN1_STRING **val;
  int iVar1;
  uchar *buf;
  ASN1_STRING *pAVar2;
  ASN1_OBJECT *aobj;
  int in_GS_OFFSET;
  ASN1_STRING *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  alg_00 = X509_ALGOR_new();
  if (alg_00 == (X509_ALGOR *)0x0) {
    ERR_put_error(0xd,0xca,0x41,"p5_pbe.c",0x86);
    alg_00 = (X509_ALGOR *)0x0;
    goto LAB_08151bd1;
  }
  local_24 = (ASN1_STRING *)0x0;
  val = (ASN1_STRING **)ASN1_item_new((ASN1_ITEM *)PBEPARAM_it);
  if (val == (ASN1_STRING **)0x0) {
    ERR_put_error(0xd,0xd7,0x41,"p5_pbe.c",0x56);
  }
  else {
    if (iter < 1) {
      iter = 0x800;
    }
    iVar1 = ASN1_INTEGER_set(val[1],iter);
    if (iVar1 == 0) {
      iVar1 = 0x5c;
LAB_08151b88:
      ERR_put_error(0xd,0xd7,0x41,"p5_pbe.c",iVar1);
    }
    else {
      if (saltlen == 0) {
        saltlen = 8;
      }
      iVar1 = ASN1_STRING_set(*val,(void *)0x0,saltlen);
      if (iVar1 == 0) {
        iVar1 = 0x62;
        goto LAB_08151b88;
      }
      buf = ASN1_STRING_data(*val);
      if (salt != (uchar *)0x0) {
        memcpy(buf,salt,saltlen);
LAB_08151c17:
        pAVar2 = ASN1_item_pack(val,(ASN1_ITEM *)PBEPARAM_it,&local_24);
        if (pAVar2 != (ASN1_STRING *)0x0) {
          ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PBEPARAM_it);
          pAVar2 = local_24;
          aobj = OBJ_nid2obj(alg);
          iVar1 = X509_ALGOR_set0(alg_00,aobj,0x10,pAVar2);
          if (iVar1 != 0) goto LAB_08151bd1;
          goto LAB_08151baf;
        }
        iVar1 = 0x6c;
        goto LAB_08151b88;
      }
      iVar1 = RAND_bytes(buf,saltlen);
      if (0 < iVar1) goto LAB_08151c17;
    }
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PBEPARAM_it);
  }
LAB_08151baf:
  if (local_24 != (ASN1_STRING *)0x0) {
    ASN1_STRING_free(local_24);
  }
  X509_ALGOR_free(alg_00);
  alg_00 = (X509_ALGOR *)0x0;
LAB_08151bd1:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return alg_00;
}

