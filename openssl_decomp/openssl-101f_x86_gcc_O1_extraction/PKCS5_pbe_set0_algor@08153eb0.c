
int PKCS5_pbe_set0_algor(X509_ALGOR *algor,int alg,int iter,uchar *salt,int saltlen)

{
  ASN1_STRING **val;
  int iVar1;
  uchar *buf;
  ASN1_STRING *pAVar2;
  ASN1_OBJECT *aobj;
  int iVar3;
  int in_GS_OFFSET;
  ASN1_STRING *local_24;
  int local_20;
  
  local_24 = (ASN1_STRING *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  val = (ASN1_STRING **)ASN1_item_new((ASN1_ITEM *)PBEPARAM_it);
  if (val == (ASN1_STRING **)0x0) {
    ERR_put_error(0xd,0xd7,0x41,"p5_pbe.c",0x57);
  }
  else {
    if (iter < 1) {
      iter = 0x800;
    }
    iVar1 = ASN1_INTEGER_set(val[1],iter);
    if (iVar1 == 0) {
      iVar1 = 0x5e;
LAB_08153f3a:
      ERR_put_error(0xd,0xd7,0x41,"p5_pbe.c",iVar1);
    }
    else {
      if (saltlen == 0) {
        saltlen = 8;
      }
      iVar1 = ASN1_STRING_set(*val,(void *)0x0,saltlen);
      if (iVar1 == 0) {
        iVar1 = 0x65;
        goto LAB_08153f3a;
      }
      buf = ASN1_STRING_data(*val);
      if (salt != (uchar *)0x0) {
        memcpy(buf,salt,saltlen);
LAB_08153fbb:
        pAVar2 = ASN1_item_pack(val,(ASN1_ITEM *)PBEPARAM_it,&local_24);
        if (pAVar2 != (ASN1_STRING *)0x0) {
          ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PBEPARAM_it);
          pAVar2 = local_24;
          aobj = OBJ_nid2obj(alg);
          iVar3 = 1;
          iVar1 = X509_ALGOR_set0(algor,aobj,0x10,pAVar2);
          if (iVar1 != 0) goto LAB_08153f77;
          goto LAB_08153f61;
        }
        iVar1 = 0x70;
        goto LAB_08153f3a;
      }
      iVar1 = RAND_pseudo_bytes(buf,saltlen);
      if (-1 < iVar1) goto LAB_08153fbb;
    }
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PBEPARAM_it);
  }
LAB_08153f61:
  iVar3 = 0;
  if (local_24 != (ASN1_STRING *)0x0) {
    ASN1_STRING_free(local_24);
  }
LAB_08153f77:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}

