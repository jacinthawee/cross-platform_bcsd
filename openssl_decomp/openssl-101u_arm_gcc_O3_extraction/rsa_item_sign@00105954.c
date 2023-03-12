
ASN1_STRING *
rsa_item_sign(EVP_MD_CTX *param_1,undefined4 param_2,undefined4 param_3,X509_ALGOR *param_4,
             X509_ALGOR *param_5)

{
  int iVar1;
  EVP_PKEY *pkey;
  EVP_MD *md;
  RSA_PSS_PARAMS *a;
  ASN1_INTEGER *a_00;
  X509_ALGOR *pXVar2;
  X509_ALGOR *alg;
  ASN1_OBJECT *pAVar3;
  int iVar4;
  ASN1_STRING *pAVar5;
  EVP_PKEY_CTX *ctx;
  int local_34;
  EVP_MD *local_30;
  ASN1_STRING *local_2c;
  int local_28;
  ASN1_OCTET_STRING *local_24 [2];
  
  ctx = param_1->pctx;
  iVar1 = EVP_PKEY_CTX_ctrl(ctx,6,-1,0x1006,0,&local_34);
  if (iVar1 < 1) {
    return (ASN1_STRING *)0x0;
  }
  if (local_34 != 6) {
    return (ASN1_STRING *)0x2;
  }
  local_2c = (ASN1_STRING *)0x0;
  pkey = EVP_PKEY_CTX_get0_pkey(ctx);
  md = EVP_MD_CTX_md(param_1);
  iVar1 = EVP_PKEY_CTX_ctrl(ctx,6,0xf8,0x1008,0,&local_30);
  if ((0 < iVar1) && (iVar1 = EVP_PKEY_CTX_ctrl(ctx,6,0x18,0x1007,0,&local_28), iVar1 != 0)) {
    if (local_28 == -1) {
      local_28 = EVP_MD_size(md);
    }
    else if (local_28 == -2) {
      iVar1 = EVP_PKEY_size(pkey);
      iVar4 = EVP_MD_size(md);
      local_28 = (iVar1 - iVar4) + -2;
      iVar1 = EVP_PKEY_bits(pkey);
      if ((iVar1 - 1U & 7) == 0) {
        local_28 = local_28 + -1;
      }
    }
    a = RSA_PSS_PARAMS_new();
    if (a != (RSA_PSS_PARAMS *)0x0) {
      if (local_28 == 0x14) {
LAB_00105a14:
        iVar1 = EVP_MD_type(md);
        if (iVar1 != 0x40) {
          pXVar2 = X509_ALGOR_new();
          a->hashAlgorithm = pXVar2;
          if (pXVar2 == (X509_ALGOR *)0x0) goto LAB_001059f8;
          X509_ALGOR_set_md(pXVar2,md);
        }
        iVar1 = EVP_MD_type(local_30);
        if (iVar1 == 0x40) {
          pXVar2 = (X509_ALGOR *)0x0;
LAB_00105a7c:
          pAVar5 = ASN1_item_pack(a,(ASN1_ITEM *)&RSA_PSS_PARAMS_it,&local_2c);
          if (pAVar5 != (ASN1_STRING *)0x0) {
            if (param_5 != (X509_ALGOR *)0x0) {
              pAVar5 = ASN1_STRING_dup(local_2c);
              if (pAVar5 == (ASN1_STRING *)0x0) goto LAB_00105acc;
              pAVar3 = OBJ_nid2obj(0x390);
              X509_ALGOR_set0(param_5,pAVar3,0x10,pAVar5);
            }
            pAVar5 = (ASN1_STRING *)0x3;
            pAVar3 = OBJ_nid2obj(0x390);
            X509_ALGOR_set0(param_4,pAVar3,0x10,local_2c);
            local_2c = (ASN1_STRING *)0x0;
          }
        }
        else {
          local_24[0] = (ASN1_OCTET_STRING *)0x0;
          pXVar2 = X509_ALGOR_new();
          X509_ALGOR_set_md(pXVar2,local_30);
          pAVar5 = ASN1_item_pack(pXVar2,(ASN1_ITEM *)&X509_ALGOR_it,local_24);
          if (pAVar5 != (ASN1_STRING *)0x0) {
            alg = X509_ALGOR_new();
            a->maskGenAlgorithm = alg;
            if (alg != (X509_ALGOR *)0x0) {
              pAVar3 = OBJ_nid2obj(0x38f);
              X509_ALGOR_set0(alg,pAVar3,0x10,local_24[0]);
              goto LAB_00105a7c;
            }
          }
          pAVar5 = (ASN1_STRING *)0x0;
        }
LAB_00105acc:
        if (pXVar2 != (X509_ALGOR *)0x0) {
          X509_ALGOR_free(pXVar2);
        }
      }
      else {
        a_00 = ASN1_INTEGER_new();
        a->saltLength = a_00;
        if ((a_00 != (ASN1_INTEGER *)0x0) && (iVar1 = ASN1_INTEGER_set(a_00,local_28), iVar1 != 0))
        goto LAB_00105a14;
LAB_001059f8:
        pAVar5 = (ASN1_STRING *)0x0;
      }
      RSA_PSS_PARAMS_free(a);
      goto LAB_00105a00;
    }
  }
  pAVar5 = (ASN1_STRING *)0x0;
LAB_00105a00:
  if (local_2c != (ASN1_STRING *)0x0) {
    ASN1_STRING_free(local_2c);
  }
  return pAVar5;
}

