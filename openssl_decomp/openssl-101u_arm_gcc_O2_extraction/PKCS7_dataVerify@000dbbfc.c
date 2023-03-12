
int PKCS7_dataVerify(X509_STORE *cert_store,X509_STORE_CTX *ctx,BIO *bio,PKCS7 *p7,
                    PKCS7_SIGNER_INFO *si)

{
  EVP_MD *pEVar1;
  int iVar2;
  BIO *bp;
  EVP_PKEY *pkey;
  ASN1_OBJECT *b;
  ASN1_OBJECT **ppAVar3;
  void *pvVar4;
  char *name;
  size_t cnt;
  int iVar5;
  X509 *x509;
  size_t *psVar6;
  _STACK *val;
  ASN1_OCTET_STRING *pAVar7;
  int iVar8;
  stack_st_X509 *sk;
  EVP_MD_CTX *pEStack_90;
  uchar *puStack_8c;
  size_t sStack_88;
  EVP_MD_CTX EStack_84;
  uchar auStack_6c [64];
  int iStack_2c;
  
  if (p7 == (PKCS7 *)0x0) {
    ERR_put_error(0x21,0x6b,0x8f,"pk7_doit.c",0x3d3);
    return 0;
  }
  if ((p7->d).ptr == (char *)0x0) {
    ERR_put_error(0x21,0x6b,0x7a,"pk7_doit.c",0x3d8);
    return 0;
  }
  iVar5 = OBJ_obj2nid(p7->type);
  if ((iVar5 != 0x16) && (iVar5 = OBJ_obj2nid(p7->type), iVar5 != 0x18)) {
    ERR_put_error(0x21,0x6b,0x72,"pk7_doit.c",0x3e1);
    return 0;
  }
  sk = ((p7->d).sign)->cert;
  x509 = X509_find_by_issuer_and_serial
                   (sk,si->issuer_and_serial->issuer,si->issuer_and_serial->serial);
  if (x509 == (X509 *)0x0) {
    ERR_put_error(0x21,0x6b,0x6a,"pk7_doit.c",0x3ec);
    return 0;
  }
  iVar5 = X509_STORE_CTX_init(ctx,cert_store,x509,sk);
  if (iVar5 == 0) {
    ERR_put_error(0x21,0x6b,0xb,"pk7_doit.c",0x3f2);
    return 0;
  }
  X509_STORE_CTX_set_purpose(ctx,4);
  iVar5 = X509_verify_cert(ctx);
  if (iVar5 < 1) {
    ERR_put_error(0x21,0x6b,0xb,"pk7_doit.c",0x3f8);
    X509_STORE_CTX_cleanup(ctx);
    return 0;
  }
  X509_STORE_CTX_cleanup(ctx);
  iStack_2c = __stack_chk_guard;
  EVP_MD_CTX_init(&EStack_84);
  iVar5 = OBJ_obj2nid(p7->type);
  if ((iVar5 != 0x16) && (iVar5 = OBJ_obj2nid(p7->type), iVar5 != 0x18)) {
    pEStack_90 = (EVP_MD_CTX *)0x0;
    ERR_put_error(0x21,0x71,0x72,"pk7_doit.c",0x411);
    goto LAB_000dba58;
  }
  iVar5 = OBJ_obj2nid(si->digest_alg->algorithm);
  if (bio != (BIO *)0x0) {
    do {
      bp = BIO_find_type(bio,0x208);
      if (bp == (BIO *)0x0) break;
      BIO_ctrl(bp,0x78,0,&pEStack_90);
      if (pEStack_90 == (EVP_MD_CTX *)0x0) {
        ERR_put_error(0x21,0x71,0x44,"pk7_doit.c",0x421);
        goto LAB_000dba58;
      }
      pEVar1 = EVP_MD_CTX_md(pEStack_90);
      iVar2 = EVP_MD_type(pEVar1);
      if (iVar2 == iVar5) {
LAB_000dba70:
        iVar2 = EVP_MD_CTX_copy_ex(&EStack_84,pEStack_90);
        if (iVar2 == 0) goto LAB_000dbad4;
        val = (_STACK *)si->auth_attr;
        if ((val == (_STACK *)0x0) || (iVar2 = sk_num(val), iVar2 == 0)) goto LAB_000dba88;
        iVar8 = 0;
        puStack_8c = (uchar *)0x0;
        iVar2 = EVP_DigestFinal_ex(&EStack_84,auStack_6c,&sStack_88);
        if (iVar2 == 0) goto LAB_000dbad4;
        b = OBJ_nid2obj(0x33);
        if (b != (ASN1_OBJECT *)0x0) goto LAB_000dbb26;
        goto LAB_000dbb30;
      }
      pEVar1 = EVP_MD_CTX_md(pEStack_90);
      iVar2 = EVP_MD_pkey_type(pEVar1);
      if (iVar2 == iVar5) goto LAB_000dba70;
      bio = BIO_next(bp);
    } while (bio != (BIO *)0x0);
  }
  iVar5 = 0x41c;
LAB_000dba2a:
  pEStack_90 = (EVP_MD_CTX *)0x0;
  ERR_put_error(0x21,0x71,0x6c,"pk7_doit.c",iVar5);
LAB_000dba58:
  EVP_MD_CTX_cleanup(&EStack_84);
  if (iStack_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (int)pEStack_90;
LAB_000dbb26:
  iVar2 = sk_num(val);
  if (iVar2 <= iVar8) goto LAB_000dbb30;
  ppAVar3 = (ASN1_OBJECT **)sk_value(val,iVar8);
  iVar2 = OBJ_cmp(*ppAVar3,b);
  if (iVar2 == 0) {
    if ((((ppAVar3[1] == (ASN1_OBJECT *)0x0) && (iVar2 = sk_num((_STACK *)ppAVar3[2]), iVar2 != 0))
        && (pvVar4 = sk_value((_STACK *)ppAVar3[2],0), pvVar4 != (void *)0x0)) &&
       (psVar6 = *(size_t **)((int)pvVar4 + 4), psVar6 != (size_t *)0x0)) {
      if ((*psVar6 == sStack_88) &&
         (iVar2 = memcmp((void *)psVar6[2],auStack_6c,*psVar6), iVar2 == 0)) {
        name = OBJ_nid2sn(iVar5);
        pEVar1 = EVP_get_digestbyname(name);
        iVar5 = EVP_DigestInit_ex(&EStack_84,pEVar1,(ENGINE *)0x0);
        if (iVar5 == 0) goto LAB_000dbad4;
        cnt = ASN1_item_i2d((ASN1_VALUE *)val,&puStack_8c,(ASN1_ITEM *)PKCS7_ATTR_VERIFY_it);
        if ((int)cnt < 1) {
          pEStack_90 = (EVP_MD_CTX *)0xffffffff;
          ERR_put_error(0x21,0x71,0xd,"pk7_doit.c",0x45d);
        }
        else {
          iVar5 = EVP_DigestUpdate(&EStack_84,puStack_8c,cnt);
          if (iVar5 != 0) {
            CRYPTO_free(puStack_8c);
LAB_000dba88:
            pAVar7 = si->enc_digest;
            pkey = X509_get_pubkey(x509);
            if (pkey == (EVP_PKEY *)0x0) {
              pEStack_90 = (EVP_MD_CTX *)0xffffffff;
            }
            else {
              iVar5 = EVP_VerifyFinal(&EStack_84,pAVar7->data,pAVar7->length,pkey);
              EVP_PKEY_free(pkey);
              if (iVar5 < 1) {
                pEStack_90 = (EVP_MD_CTX *)0xffffffff;
                ERR_put_error(0x21,0x71,0x69,"pk7_doit.c",0x471);
              }
              else {
                pEStack_90 = (EVP_MD_CTX *)0x1;
              }
            }
            goto LAB_000dba58;
          }
LAB_000dbad4:
          pEStack_90 = (EVP_MD_CTX *)0x0;
        }
      }
      else {
        pEStack_90 = (EVP_MD_CTX *)0xffffffff;
        ERR_put_error(0x21,0x71,0x65,"pk7_doit.c",0x452);
      }
      goto LAB_000dba58;
    }
    goto LAB_000dbb30;
  }
  iVar8 = iVar8 + 1;
  goto LAB_000dbb26;
LAB_000dbb30:
  iVar5 = 0x442;
  goto LAB_000dba2a;
}

