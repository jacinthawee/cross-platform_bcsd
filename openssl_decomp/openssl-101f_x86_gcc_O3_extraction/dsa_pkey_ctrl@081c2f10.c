
undefined4 dsa_pkey_ctrl(EVP_PKEY *param_1,int param_2,int param_3,PKCS7_SIGNER_INFO *param_4)

{
  int iVar1;
  int pkey_nid;
  ASN1_OBJECT *aobj;
  undefined4 uVar2;
  int in_GS_OFFSET;
  int local_1c;
  X509_ALGOR *local_18;
  X509_ALGOR *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_2 == 3) {
    param_4->version = (ASN1_INTEGER *)0x40;
    uVar2 = 2;
  }
  else {
    if (param_2 == 5) {
      uVar2 = 1;
      if (param_3 != 0) goto LAB_081c2f47;
      CMS_SignerInfo_get0_algs
                ((CMS_SignerInfo *)param_4,(EVP_PKEY **)0x0,(X509 **)0x0,&local_18,&local_14);
    }
    else {
      uVar2 = 0xfffffffe;
      if ((param_2 != 1) || (uVar2 = 1, param_3 != 0)) goto LAB_081c2f47;
      PKCS7_SIGNER_INFO_get0_algs(param_4,(EVP_PKEY **)0x0,&local_18,&local_14);
    }
    if (local_18 != (X509_ALGOR *)0x0) {
      uVar2 = 1;
      if ((local_18->algorithm != (ASN1_OBJECT *)0x0) &&
         (iVar1 = OBJ_obj2nid(local_18->algorithm), iVar1 != 0)) {
        pkey_nid = EVP_PKEY_id(param_1);
        iVar1 = OBJ_find_sigid_by_algs(&local_1c,iVar1,pkey_nid);
        if (iVar1 != 0) {
          aobj = OBJ_nid2obj(local_1c);
          X509_ALGOR_set0(local_14,aobj,-1,(void *)0x0);
          goto LAB_081c2f47;
        }
      }
    }
    uVar2 = 0xffffffff;
  }
LAB_081c2f47:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

