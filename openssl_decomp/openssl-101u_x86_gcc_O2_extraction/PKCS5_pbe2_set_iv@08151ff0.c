
X509_ALGOR *
PKCS5_pbe2_set_iv(EVP_CIPHER *cipher,int iter,uchar *salt,int saltlen,uchar *aiv,int prf_nid)

{
  int n;
  ASN1_OBJECT *pAVar1;
  X509_ALGOR **val;
  ASN1_TYPE *pAVar2;
  int iVar3;
  X509_ALGOR *pXVar4;
  ASN1_STRING *pAVar5;
  int in_GS_OFFSET;
  uchar *local_c4;
  EVP_CIPHER_CTX local_bc;
  uchar local_30 [16];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  n = EVP_CIPHER_type(cipher);
  if (n == 0) {
    val = (X509_ALGOR **)0x0;
    pXVar4 = (X509_ALGOR *)0x0;
    ERR_put_error(0xd,0xa7,0x6c,"p5_pbev2.c",0x68);
  }
  else {
    pAVar1 = OBJ_nid2obj(n);
    val = (X509_ALGOR **)ASN1_item_new((ASN1_ITEM *)PBE2PARAM_it);
    if (val == (X509_ALGOR **)0x0) {
LAB_08152260:
      pXVar4 = (X509_ALGOR *)0x0;
    }
    else {
      pXVar4 = val[1];
      pXVar4->algorithm = pAVar1;
      pAVar2 = ASN1_TYPE_new();
      pXVar4->parameter = pAVar2;
      if (pAVar2 == (ASN1_TYPE *)0x0) goto LAB_08152260;
      iVar3 = EVP_CIPHER_iv_length(cipher);
      if (iVar3 != 0) {
        if (aiv != (uchar *)0x0) {
          iVar3 = EVP_CIPHER_iv_length(cipher);
          __memcpy_chk(local_30,aiv,iVar3,0x10);
          goto LAB_081520b9;
        }
        iVar3 = EVP_CIPHER_iv_length(cipher);
        iVar3 = RAND_bytes(local_30,iVar3);
        if (0 < iVar3) goto LAB_081520b9;
LAB_08152230:
        pXVar4 = (X509_ALGOR *)0x0;
        goto LAB_08152232;
      }
LAB_081520b9:
      local_c4 = local_30;
      EVP_CIPHER_CTX_init(&local_bc);
      iVar3 = EVP_CipherInit_ex(&local_bc,cipher,(ENGINE *)0x0,(uchar *)0x0,local_c4,0);
      if (iVar3 == 0) goto LAB_08152230;
      iVar3 = EVP_CIPHER_param_to_asn1(&local_bc,pXVar4->parameter);
      if (iVar3 < 0) {
        pXVar4 = (X509_ALGOR *)0x0;
        ERR_put_error(0xd,0xa7,0x72,"p5_pbev2.c",0x85);
        EVP_CIPHER_CTX_cleanup(&local_bc);
        goto LAB_08152232;
      }
      if ((prf_nid == -1) && (iVar3 = EVP_CIPHER_CTX_ctrl(&local_bc,7,0,&prf_nid), iVar3 < 1)) {
        ERR_clear_error();
        prf_nid = 0xa3;
      }
      iVar3 = -1;
      EVP_CIPHER_CTX_cleanup(&local_bc);
      if (n == 0x25) {
        iVar3 = EVP_CIPHER_key_length(cipher);
      }
      X509_ALGOR_free(*val);
      pXVar4 = PKCS5_pbkdf2_set(iter,salt,saltlen,prf_nid,iVar3);
      *val = pXVar4;
      if ((pXVar4 == (X509_ALGOR *)0x0) || (pXVar4 = X509_ALGOR_new(), pXVar4 == (X509_ALGOR *)0x0))
      goto LAB_08152260;
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
          goto LAB_081521c9;
        }
      }
    }
    ERR_put_error(0xd,0xa7,0x41,"p5_pbev2.c",0xba);
  }
LAB_08152232:
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PBE2PARAM_it);
  X509_ALGOR_free((X509_ALGOR *)0x0);
  X509_ALGOR_free(pXVar4);
  pXVar4 = (X509_ALGOR *)0x0;
LAB_081521c9:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pXVar4;
}

