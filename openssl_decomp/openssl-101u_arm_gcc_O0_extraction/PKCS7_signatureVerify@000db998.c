
int PKCS7_signatureVerify(BIO *bio,PKCS7 *p7,PKCS7_SIGNER_INFO *si,X509 *x509)

{
  int iVar1;
  EVP_MD *pEVar2;
  int iVar3;
  BIO *bp;
  EVP_PKEY *pkey;
  ASN1_OBJECT *b;
  ASN1_OBJECT **ppAVar4;
  void *pvVar5;
  char *name;
  size_t cnt;
  size_t *psVar6;
  _STACK *val;
  ASN1_OCTET_STRING *pAVar7;
  int iVar8;
  EVP_MD_CTX *local_90;
  uchar *local_8c;
  size_t local_88;
  EVP_MD_CTX EStack_84;
  uchar auStack_6c [64];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  EVP_MD_CTX_init(&EStack_84);
  iVar1 = OBJ_obj2nid(p7->type);
  if ((iVar1 != 0x16) && (iVar1 = OBJ_obj2nid(p7->type), iVar1 != 0x18)) {
    local_90 = (EVP_MD_CTX *)0x0;
    ERR_put_error(0x21,0x71,0x72,"pk7_doit.c",0x411);
    goto LAB_000dba58;
  }
  iVar1 = OBJ_obj2nid(si->digest_alg->algorithm);
  if (bio != (BIO *)0x0) {
    do {
      bp = BIO_find_type(bio,0x208);
      if (bp == (BIO *)0x0) break;
      BIO_ctrl(bp,0x78,0,&local_90);
      if (local_90 == (EVP_MD_CTX *)0x0) {
        ERR_put_error(0x21,0x71,0x44,"pk7_doit.c",0x421);
        goto LAB_000dba58;
      }
      pEVar2 = EVP_MD_CTX_md(local_90);
      iVar3 = EVP_MD_type(pEVar2);
      if (iVar3 == iVar1) {
LAB_000dba70:
        iVar3 = EVP_MD_CTX_copy_ex(&EStack_84,local_90);
        if (iVar3 == 0) goto LAB_000dbad4;
        val = (_STACK *)si->auth_attr;
        if ((val == (_STACK *)0x0) || (iVar3 = sk_num(val), iVar3 == 0)) goto LAB_000dba88;
        iVar8 = 0;
        local_8c = (uchar *)0x0;
        iVar3 = EVP_DigestFinal_ex(&EStack_84,auStack_6c,&local_88);
        if (iVar3 == 0) goto LAB_000dbad4;
        b = OBJ_nid2obj(0x33);
        if (b == (ASN1_OBJECT *)0x0) goto LAB_000dbb30;
        goto LAB_000dbb26;
      }
      pEVar2 = EVP_MD_CTX_md(local_90);
      iVar3 = EVP_MD_pkey_type(pEVar2);
      if (iVar3 == iVar1) goto LAB_000dba70;
      bio = BIO_next(bp);
    } while (bio != (BIO *)0x0);
  }
  iVar1 = 0x41c;
LAB_000dba2a:
  local_90 = (EVP_MD_CTX *)0x0;
  ERR_put_error(0x21,0x71,0x6c,"pk7_doit.c",iVar1);
LAB_000dba58:
  EVP_MD_CTX_cleanup(&EStack_84);
  if (local_2c == __stack_chk_guard) {
    return (int)local_90;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_000dbb26:
  iVar3 = sk_num(val);
  if (iVar3 <= iVar8) goto LAB_000dbb30;
  ppAVar4 = (ASN1_OBJECT **)sk_value(val,iVar8);
  iVar3 = OBJ_cmp(*ppAVar4,b);
  if (iVar3 == 0) {
    if ((((ppAVar4[1] == (ASN1_OBJECT *)0x0) && (iVar3 = sk_num((_STACK *)ppAVar4[2]), iVar3 != 0))
        && (pvVar5 = sk_value((_STACK *)ppAVar4[2],0), pvVar5 != (void *)0x0)) &&
       (psVar6 = *(size_t **)((int)pvVar5 + 4), psVar6 != (size_t *)0x0)) {
      if ((*psVar6 == local_88) &&
         (iVar3 = memcmp((void *)psVar6[2],auStack_6c,*psVar6), iVar3 == 0)) {
        name = OBJ_nid2sn(iVar1);
        pEVar2 = EVP_get_digestbyname(name);
        iVar1 = EVP_DigestInit_ex(&EStack_84,pEVar2,(ENGINE *)0x0);
        if (iVar1 == 0) goto LAB_000dbad4;
        cnt = ASN1_item_i2d((ASN1_VALUE *)val,&local_8c,(ASN1_ITEM *)PKCS7_ATTR_VERIFY_it);
        if ((int)cnt < 1) {
          local_90 = (EVP_MD_CTX *)0xffffffff;
          ERR_put_error(0x21,0x71,0xd,"pk7_doit.c",0x45d);
        }
        else {
          iVar1 = EVP_DigestUpdate(&EStack_84,local_8c,cnt);
          if (iVar1 != 0) {
            CRYPTO_free(local_8c);
LAB_000dba88:
            pAVar7 = si->enc_digest;
            pkey = X509_get_pubkey(x509);
            if (pkey == (EVP_PKEY *)0x0) {
              local_90 = (EVP_MD_CTX *)0xffffffff;
            }
            else {
              iVar1 = EVP_VerifyFinal(&EStack_84,pAVar7->data,pAVar7->length,pkey);
              EVP_PKEY_free(pkey);
              if (iVar1 < 1) {
                local_90 = (EVP_MD_CTX *)0xffffffff;
                ERR_put_error(0x21,0x71,0x69,"pk7_doit.c",0x471);
              }
              else {
                local_90 = (EVP_MD_CTX *)0x1;
              }
            }
            goto LAB_000dba58;
          }
LAB_000dbad4:
          local_90 = (EVP_MD_CTX *)0x0;
        }
      }
      else {
        local_90 = (EVP_MD_CTX *)0xffffffff;
        ERR_put_error(0x21,0x71,0x65,"pk7_doit.c",0x452);
      }
      goto LAB_000dba58;
    }
    goto LAB_000dbb30;
  }
  iVar8 = iVar8 + 1;
  goto LAB_000dbb26;
LAB_000dbb30:
  iVar1 = 0x442;
  goto LAB_000dba2a;
}

