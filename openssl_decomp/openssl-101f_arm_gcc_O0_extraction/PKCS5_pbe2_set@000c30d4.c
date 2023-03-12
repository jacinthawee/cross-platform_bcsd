
X509_ALGOR * PKCS5_pbe2_set(EVP_CIPHER *cipher,int iter,uchar *salt,int saltlen)

{
  X509_ALGOR *n;
  ASN1_OBJECT *pAVar1;
  X509_ALGOR *val;
  ASN1_STRING *pAVar2;
  int iVar3;
  X509_ALGOR *a;
  ASN1_TYPE *pAVar4;
  int local_cc;
  uchar auStack_c8 [16];
  EVP_CIPHER_CTX EStack_b8;
  int local_2c;
  
  local_cc = -1;
  local_2c = __TMC_END__;
  n = (X509_ALGOR *)EVP_CIPHER_type(cipher);
  if (n == (X509_ALGOR *)0x0) {
    ERR_put_error(0xd,0xa7,0x6c,"p5_pbev2.c",0x67);
    val = n;
    a = n;
    goto LAB_000c3208;
  }
  pAVar1 = OBJ_nid2obj((int)n);
  val = (X509_ALGOR *)ASN1_item_new((ASN1_ITEM *)&PBE2PARAM_it);
  if (val == (X509_ALGOR *)0x0) {
LAB_000c3226:
    a = (X509_ALGOR *)0x0;
LAB_000c3228:
    ERR_put_error(0xd,0xa7,0x41,"p5_pbev2.c",0xb6);
  }
  else {
    pAVar4 = val->parameter;
    pAVar4->type = (int)pAVar1;
    pAVar2 = (ASN1_STRING *)ASN1_TYPE_new();
    (pAVar4->value).asn1_string = pAVar2;
    if (pAVar2 == (ASN1_STRING *)0x0) goto LAB_000c3226;
    iVar3 = EVP_CIPHER_iv_length(cipher);
    if (iVar3 != 0) {
      iVar3 = EVP_CIPHER_iv_length(cipher);
      iVar3 = RAND_pseudo_bytes(auStack_c8,iVar3);
      if (iVar3 < 0) {
        a = (X509_ALGOR *)0x0;
        goto LAB_000c3208;
      }
    }
    EVP_CIPHER_CTX_init(&EStack_b8);
    a = (X509_ALGOR *)EVP_CipherInit_ex(&EStack_b8,cipher,(ENGINE *)0x0,(uchar *)0x0,auStack_c8,0);
    if (a != (X509_ALGOR *)0x0) {
      iVar3 = EVP_CIPHER_param_to_asn1(&EStack_b8,(ASN1_TYPE *)(pAVar4->value).asn1_string);
      if (iVar3 < 0) {
        ERR_put_error(0xd,0xa7,0x72,"p5_pbev2.c",0x84);
        EVP_CIPHER_CTX_cleanup(&EStack_b8);
        a = (X509_ALGOR *)0x0;
        goto LAB_000c3208;
      }
      if ((local_cc == -1) && (iVar3 = EVP_CIPHER_CTX_ctrl(&EStack_b8,7,0,&local_cc), iVar3 < 1)) {
        ERR_clear_error();
        local_cc = 0xa3;
      }
      EVP_CIPHER_CTX_cleanup(&EStack_b8);
      if (n == (X509_ALGOR *)0x25) {
        iVar3 = EVP_CIPHER_key_length(cipher);
      }
      else {
        iVar3 = -1;
      }
      X509_ALGOR_free((X509_ALGOR *)val->algorithm);
      pAVar1 = (ASN1_OBJECT *)PKCS5_pbkdf2_set(iter,salt,saltlen,local_cc,iVar3);
      val->algorithm = pAVar1;
      if ((pAVar1 == (ASN1_OBJECT *)0x0) || (a = X509_ALGOR_new(), a == (X509_ALGOR *)0x0))
      goto LAB_000c3226;
      pAVar4 = ASN1_TYPE_new();
      a->parameter = pAVar4;
      if (pAVar4 != (ASN1_TYPE *)0x0) {
        pAVar1 = OBJ_nid2obj(0xa1);
        a->algorithm = pAVar1;
        pAVar2 = ASN1_item_pack(val,(ASN1_ITEM *)&PBE2PARAM_it,&(a->parameter->value).octet_string);
        if (pAVar2 != (ASN1_STRING *)0x0) {
          a->parameter->type = 0x10;
          ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)&PBE2PARAM_it);
          goto LAB_000c31f2;
        }
      }
      goto LAB_000c3228;
    }
  }
LAB_000c3208:
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)&PBE2PARAM_it);
  X509_ALGOR_free((X509_ALGOR *)0x0);
  X509_ALGOR_free(a);
  a = (X509_ALGOR *)0x0;
LAB_000c31f2:
  if (local_2c == __TMC_END__) {
    return a;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}
