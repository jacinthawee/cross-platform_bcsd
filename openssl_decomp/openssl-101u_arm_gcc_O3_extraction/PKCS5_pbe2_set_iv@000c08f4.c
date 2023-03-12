
X509_ALGOR *
PKCS5_pbe2_set_iv(EVP_CIPHER *cipher,int iter,uchar *salt,int saltlen,uchar *aiv,int prf_nid)

{
  X509_ALGOR *n;
  ASN1_OBJECT *pAVar1;
  X509_ALGOR *val;
  ASN1_STRING *pAVar2;
  int iVar3;
  ASN1_TYPE *pAVar4;
  uchar auStack_c8 [16];
  EVP_CIPHER_CTX EStack_b8;
  int local_2c;
  
  local_2c = __stack_chk_guard;
  n = (X509_ALGOR *)EVP_CIPHER_type(cipher);
  if (n == (X509_ALGOR *)0x0) {
    ERR_put_error(0xd,0xa7,0x6c,"p5_pbev2.c",0x68);
    val = n;
    aiv = (uchar *)n;
    goto LAB_000c0a22;
  }
  pAVar1 = OBJ_nid2obj((int)n);
  val = (X509_ALGOR *)ASN1_item_new((ASN1_ITEM *)&PBE2PARAM_it);
  if (val == (X509_ALGOR *)0x0) {
LAB_000c0a40:
    aiv = (uchar *)0x0;
LAB_000c0a42:
    ERR_put_error(0xd,0xa7,0x41,"p5_pbev2.c",0xba);
  }
  else {
    pAVar4 = val->parameter;
    pAVar4->type = (int)pAVar1;
    pAVar2 = (ASN1_STRING *)ASN1_TYPE_new();
    (pAVar4->value).asn1_string = pAVar2;
    if (pAVar2 == (ASN1_STRING *)0x0) goto LAB_000c0a40;
    iVar3 = EVP_CIPHER_iv_length(cipher);
    if (iVar3 != 0) {
      if (aiv == (uchar *)0x0) {
        iVar3 = EVP_CIPHER_iv_length(cipher);
        iVar3 = RAND_bytes(auStack_c8,iVar3);
        if (iVar3 < 1) goto LAB_000c0a22;
      }
      else {
        iVar3 = EVP_CIPHER_iv_length(cipher);
        __memcpy_chk(auStack_c8,aiv,iVar3,0x10);
      }
    }
    EVP_CIPHER_CTX_init(&EStack_b8);
    aiv = (uchar *)EVP_CipherInit_ex(&EStack_b8,cipher,(ENGINE *)0x0,(uchar *)0x0,auStack_c8,0);
    if ((X509_ALGOR *)aiv != (X509_ALGOR *)0x0) {
      iVar3 = EVP_CIPHER_param_to_asn1(&EStack_b8,(ASN1_TYPE *)(pAVar4->value).asn1_string);
      if (iVar3 < 0) {
        ERR_put_error(0xd,0xa7,0x72,"p5_pbev2.c",0x85);
        EVP_CIPHER_CTX_cleanup(&EStack_b8);
        aiv = (uchar *)(X509_ALGOR *)0x0;
        goto LAB_000c0a22;
      }
      if ((prf_nid == -1) && (iVar3 = EVP_CIPHER_CTX_ctrl(&EStack_b8,7,0,&prf_nid), iVar3 < 1)) {
        ERR_clear_error();
        prf_nid = 0xa3;
      }
      EVP_CIPHER_CTX_cleanup(&EStack_b8);
      if (n == (X509_ALGOR *)0x25) {
        iVar3 = EVP_CIPHER_key_length(cipher);
      }
      else {
        iVar3 = -1;
      }
      X509_ALGOR_free((X509_ALGOR *)val->algorithm);
      pAVar1 = (ASN1_OBJECT *)PKCS5_pbkdf2_set(iter,salt,saltlen,prf_nid,iVar3);
      val->algorithm = pAVar1;
      if ((pAVar1 == (ASN1_OBJECT *)0x0) ||
         (aiv = (uchar *)X509_ALGOR_new(), (X509_ALGOR *)aiv == (X509_ALGOR *)0x0))
      goto LAB_000c0a40;
      pAVar4 = ASN1_TYPE_new();
      *(ASN1_TYPE **)((int)aiv + 4) = pAVar4;
      if (pAVar4 != (ASN1_TYPE *)0x0) {
        pAVar1 = OBJ_nid2obj(0xa1);
        *(ASN1_OBJECT **)aiv = pAVar1;
        pAVar2 = ASN1_item_pack(val,(ASN1_ITEM *)&PBE2PARAM_it,
                                &((*(ASN1_TYPE **)((int)aiv + 4))->value).octet_string);
        if (pAVar2 != (ASN1_STRING *)0x0) {
          (*(ASN1_TYPE **)((int)aiv + 4))->type = 0x10;
          ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)&PBE2PARAM_it);
          goto LAB_000c0a12;
        }
      }
      goto LAB_000c0a42;
    }
  }
LAB_000c0a22:
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)&PBE2PARAM_it);
  X509_ALGOR_free((X509_ALGOR *)0x0);
  X509_ALGOR_free((X509_ALGOR *)aiv);
  aiv = (uchar *)0x0;
LAB_000c0a12:
  if (local_2c == __stack_chk_guard) {
    return (X509_ALGOR *)aiv;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

