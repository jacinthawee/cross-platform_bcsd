
undefined4
rsa_item_sign(EVP_MD_CTX *param_1,undefined4 param_2,undefined4 param_3,X509_ALGOR *param_4,
             X509_ALGOR *param_5)

{
  EVP_PKEY_CTX *ctx;
  ASN1_OCTET_STRING *pval;
  int iVar1;
  undefined4 uVar2;
  EVP_PKEY *pkey;
  EVP_MD *md;
  RSA_PSS_PARAMS *a;
  ASN1_INTEGER *a_00;
  X509_ALGOR *pXVar3;
  ASN1_STRING *pAVar4;
  X509_ALGOR *pXVar5;
  ASN1_OBJECT *pAVar6;
  int iVar7;
  int in_GS_OFFSET;
  int local_34;
  EVP_MD *local_30;
  ASN1_STRING *local_2c;
  int local_28;
  ASN1_OCTET_STRING *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  ctx = param_1->pctx;
  iVar1 = EVP_PKEY_CTX_ctrl(ctx,6,-1,0x1006,0,&local_34);
  if (iVar1 < 1) {
    uVar2 = 0;
    goto LAB_081c097b;
  }
  uVar2 = 2;
  if (local_34 != 6) goto LAB_081c097b;
  local_2c = (ASN1_STRING *)0x0;
  pkey = EVP_PKEY_CTX_get0_pkey(ctx);
  md = EVP_MD_CTX_md(param_1);
  iVar1 = EVP_PKEY_CTX_ctrl(ctx,6,0xf8,0x1008,0,&local_30);
  if ((iVar1 < 1) || (iVar1 = EVP_PKEY_CTX_ctrl(ctx,6,0x18,0x1007,0,&local_28), iVar1 == 0)) {
LAB_081c0c00:
    uVar2 = 0;
  }
  else {
    if (local_28 == -1) {
      local_28 = EVP_MD_size(md);
    }
    else if (local_28 == -2) {
      iVar1 = EVP_PKEY_size(pkey);
      iVar7 = EVP_MD_size(md);
      local_28 = (iVar1 - iVar7) + -2;
      iVar1 = EVP_PKEY_bits(pkey);
      if ((iVar1 - 1U & 7) == 0) {
        local_28 = local_28 + -1;
      }
    }
    a = RSA_PSS_PARAMS_new();
    if (a == (RSA_PSS_PARAMS *)0x0) goto LAB_081c0c00;
    if (local_28 == 0x14) {
LAB_081c0a5d:
      iVar1 = EVP_MD_type(md);
      if (iVar1 != 0x40) {
        pXVar3 = X509_ALGOR_new();
        a->hashAlgorithm = pXVar3;
        if (pXVar3 == (X509_ALGOR *)0x0) goto LAB_081c0bc7;
        X509_ALGOR_set_md(pXVar3,md);
      }
      iVar1 = EVP_MD_type(local_30);
      if (iVar1 == 0x40) {
        pAVar4 = ASN1_item_pack(a,(ASN1_ITEM *)RSA_PSS_PARAMS_it,&local_2c);
        if (pAVar4 == (ASN1_STRING *)0x0) goto LAB_081c0bc7;
        pXVar3 = (X509_ALGOR *)0x0;
LAB_081c0b3b:
        if (param_5 != (X509_ALGOR *)0x0) {
          uVar2 = 0;
          pAVar4 = ASN1_STRING_dup(local_2c);
          if (pAVar4 == (ASN1_STRING *)0x0) goto LAB_081c0bb5;
          pAVar6 = OBJ_nid2obj(0x390);
          X509_ALGOR_set0(param_5,pAVar6,0x10,pAVar4);
        }
        pAVar4 = local_2c;
        pAVar6 = OBJ_nid2obj(0x390);
        uVar2 = 3;
        X509_ALGOR_set0(param_4,pAVar6,0x10,pAVar4);
        local_2c = (ASN1_STRING *)0x0;
      }
      else {
        local_24 = (ASN1_OCTET_STRING *)0x0;
        pXVar3 = X509_ALGOR_new();
        X509_ALGOR_set_md(pXVar3,local_30);
        pAVar4 = ASN1_item_pack(pXVar3,(ASN1_ITEM *)X509_ALGOR_it,&local_24);
        if (pAVar4 != (ASN1_STRING *)0x0) {
          pXVar5 = X509_ALGOR_new();
          pval = local_24;
          a->maskGenAlgorithm = pXVar5;
          if (pXVar5 != (X509_ALGOR *)0x0) {
            pAVar6 = OBJ_nid2obj(0x38f);
            uVar2 = 0;
            X509_ALGOR_set0(a->maskGenAlgorithm,pAVar6,0x10,pval);
            pAVar4 = ASN1_item_pack(a,(ASN1_ITEM *)RSA_PSS_PARAMS_it,&local_2c);
            if (pAVar4 != (ASN1_STRING *)0x0) goto LAB_081c0b3b;
            goto LAB_081c0bb5;
          }
        }
        uVar2 = 0;
      }
LAB_081c0bb5:
      if (pXVar3 != (X509_ALGOR *)0x0) {
        X509_ALGOR_free(pXVar3);
      }
    }
    else {
      a_00 = ASN1_INTEGER_new();
      a->saltLength = a_00;
      if ((a_00 != (ASN1_INTEGER *)0x0) && (iVar1 = ASN1_INTEGER_set(a_00,local_28), iVar1 != 0))
      goto LAB_081c0a5d;
LAB_081c0bc7:
      uVar2 = 0;
    }
    RSA_PSS_PARAMS_free(a);
  }
  if (local_2c != (ASN1_STRING *)0x0) {
    ASN1_STRING_free(local_2c);
  }
LAB_081c097b:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

