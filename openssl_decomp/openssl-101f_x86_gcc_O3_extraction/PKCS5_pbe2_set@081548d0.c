
X509_ALGOR * PKCS5_pbe2_set(EVP_CIPHER *cipher,int iter,uchar *salt,int saltlen)

{
  int n;
  ASN1_OBJECT *pAVar1;
  X509_ALGOR **val;
  ASN1_TYPE *pAVar2;
  int iVar3;
  X509_ALGOR *pXVar4;
  ASN1_STRING *pAVar5;
  int in_GS_OFFSET;
  uchar *local_d4;
  int local_c0;
  EVP_CIPHER_CTX local_bc;
  uchar local_30 [16];
  int local_20;
  
  local_c0 = -1;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  n = EVP_CIPHER_type(cipher);
  if (n == 0) {
    val = (X509_ALGOR **)0x0;
    pXVar4 = (X509_ALGOR *)0x0;
    ERR_put_error(0xd,0xa7,0x6c,"p5_pbev2.c",0x67);
  }
  else {
    pAVar1 = OBJ_nid2obj(n);
    val = (X509_ALGOR **)ASN1_item_new((ASN1_ITEM *)PBE2PARAM_it);
    if (val == (X509_ALGOR **)0x0) {
LAB_08154b00:
      pXVar4 = (X509_ALGOR *)0x0;
    }
    else {
      pXVar4 = val[1];
      pXVar4->algorithm = pAVar1;
      pAVar2 = ASN1_TYPE_new();
      pXVar4->parameter = pAVar2;
      if (pAVar2 == (ASN1_TYPE *)0x0) goto LAB_08154b00;
      iVar3 = EVP_CIPHER_iv_length(cipher);
      if (iVar3 != 0) {
        iVar3 = EVP_CIPHER_iv_length(cipher);
        iVar3 = RAND_pseudo_bytes(local_30,iVar3);
        if (-1 < iVar3) goto LAB_08154993;
LAB_08154ad0:
        pXVar4 = (X509_ALGOR *)0x0;
        goto LAB_08154ad2;
      }
LAB_08154993:
      local_d4 = local_30;
      EVP_CIPHER_CTX_init(&local_bc);
      iVar3 = EVP_CipherInit_ex(&local_bc,cipher,(ENGINE *)0x0,(uchar *)0x0,local_d4,0);
      if (iVar3 == 0) goto LAB_08154ad0;
      iVar3 = EVP_CIPHER_param_to_asn1(&local_bc,pXVar4->parameter);
      if (iVar3 < 0) {
        pXVar4 = (X509_ALGOR *)0x0;
        ERR_put_error(0xd,0xa7,0x72,"p5_pbev2.c",0x84);
        EVP_CIPHER_CTX_cleanup(&local_bc);
        goto LAB_08154ad2;
      }
      if ((local_c0 == -1) && (iVar3 = EVP_CIPHER_CTX_ctrl(&local_bc,7,0,&local_c0), iVar3 < 1)) {
        ERR_clear_error();
        local_c0 = 0xa3;
      }
      iVar3 = -1;
      EVP_CIPHER_CTX_cleanup(&local_bc);
      if (n == 0x25) {
        iVar3 = EVP_CIPHER_key_length(cipher);
      }
      X509_ALGOR_free(*val);
      pXVar4 = PKCS5_pbkdf2_set(iter,salt,saltlen,local_c0,iVar3);
      *val = pXVar4;
      if ((pXVar4 == (X509_ALGOR *)0x0) || (pXVar4 = X509_ALGOR_new(), pXVar4 == (X509_ALGOR *)0x0))
      goto LAB_08154b00;
      pAVar2 = ASN1_TYPE_new();
      pXVar4->parameter = pAVar2;
      if (pAVar2 != (ASN1_TYPE *)0x0) {
        pAVar1 = OBJ_nid2obj(0xa1);
        pXVar4->algorithm = pAVar1;
        pAVar5 = ASN1_item_pack(val,(ASN1_ITEM *)PBE2PARAM_it,
                                &(pXVar4->parameter->value).octet_string);
        if (pAVar5 != (ASN1_STRING *)0x0) {
          pXVar4->parameter->type = 0x10;
          ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PBE2PARAM_it);
          goto LAB_08154a9d;
        }
      }
    }
    ERR_put_error(0xd,0xa7,0x41,"p5_pbev2.c",0xb6);
  }
LAB_08154ad2:
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PBE2PARAM_it);
  X509_ALGOR_free((X509_ALGOR *)0x0);
  X509_ALGOR_free(pXVar4);
  pXVar4 = (X509_ALGOR *)0x0;
LAB_08154a9d:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pXVar4;
}

