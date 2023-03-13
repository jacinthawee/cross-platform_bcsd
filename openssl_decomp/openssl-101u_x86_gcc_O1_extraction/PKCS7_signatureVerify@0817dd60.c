
int PKCS7_signatureVerify(BIO *bio,PKCS7 *p7,PKCS7_SIGNER_INFO *si,X509 *x509)

{
  _STACK *val;
  ASN1_OCTET_STRING *pAVar1;
  size_t *psVar2;
  int iVar3;
  EVP_MD *pEVar4;
  int iVar5;
  BIO *bp;
  EVP_PKEY *pkey;
  ASN1_OBJECT *b;
  ASN1_OBJECT **ppAVar6;
  void *pvVar7;
  char *name;
  size_t cnt;
  int iVar8;
  int in_GS_OFFSET;
  EVP_MD_CTX *local_84;
  uchar *local_80;
  size_t local_7c;
  EVP_MD_CTX local_78;
  uchar local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_MD_CTX_init(&local_78);
  iVar3 = OBJ_obj2nid(p7->type);
  if (iVar3 != 0x16) {
    iVar3 = OBJ_obj2nid(p7->type);
    if (iVar3 != 0x18) {
      iVar5 = 0x411;
      iVar3 = 0x72;
LAB_0817decf:
      ERR_put_error(0x21,0x71,iVar3,"pk7_doit.c",iVar5);
      goto LAB_0817de8f;
    }
  }
  iVar3 = OBJ_obj2nid(si->digest_alg->algorithm);
  if (bio != (BIO *)0x0) {
    do {
      bp = BIO_find_type(bio,0x208);
      if (bp == (BIO *)0x0) break;
      BIO_ctrl(bp,0x78,0,&local_84);
      if (local_84 == (EVP_MD_CTX *)0x0) {
        iVar5 = 0x421;
        iVar3 = 0x44;
        goto LAB_0817decf;
      }
      pEVar4 = EVP_MD_CTX_md(local_84);
      iVar5 = EVP_MD_type(pEVar4);
      if (iVar3 == iVar5) {
LAB_0817dee0:
        iVar8 = 0;
        iVar5 = EVP_MD_CTX_copy_ex(&local_78,local_84);
        if (iVar5 == 0) goto LAB_0817de91;
        val = (_STACK *)si->auth_attr;
        if (val == (_STACK *)0x0) goto LAB_0817df10;
        iVar5 = sk_num(val);
        if (iVar5 == 0) goto LAB_0817df10;
        local_80 = (uchar *)0x0;
        iVar5 = EVP_DigestFinal_ex(&local_78,local_60,&local_7c);
        if (iVar5 == 0) goto LAB_0817de8f;
        b = OBJ_nid2obj(0x33);
        if (b == (ASN1_OBJECT *)0x0) goto LAB_0817dff3;
        iVar5 = 0;
        goto LAB_0817dfe3;
      }
      pEVar4 = EVP_MD_CTX_md(local_84);
      iVar5 = EVP_MD_pkey_type(pEVar4);
      if (iVar3 == iVar5) goto LAB_0817dee0;
      bio = BIO_next(bp);
    } while (bio != (BIO *)0x0);
  }
  iVar3 = 0x41c;
  goto LAB_0817de7c;
LAB_0817dfe3:
  iVar8 = sk_num(val);
  if (iVar8 <= iVar5) goto LAB_0817dff3;
  ppAVar6 = (ASN1_OBJECT **)sk_value(val,iVar5);
  iVar8 = OBJ_cmp(*ppAVar6,b);
  if (iVar8 == 0) {
    if (ppAVar6[1] == (ASN1_OBJECT *)0x0) {
      iVar5 = sk_num((_STACK *)ppAVar6[2]);
      if (iVar5 != 0) {
        pvVar7 = sk_value((_STACK *)ppAVar6[2],0);
        if ((pvVar7 != (void *)0x0) &&
           (psVar2 = *(size_t **)((int)pvVar7 + 4), psVar2 != (size_t *)0x0)) {
          if (*psVar2 == local_7c) {
            iVar5 = memcmp((void *)psVar2[2],local_60,local_7c);
            if (iVar5 == 0) {
              name = OBJ_nid2sn(iVar3);
              pEVar4 = EVP_get_digestbyname(name);
              iVar3 = EVP_DigestInit_ex(&local_78,pEVar4,(ENGINE *)0x0);
              if (iVar3 == 0) goto LAB_0817de8f;
              cnt = ASN1_item_i2d((ASN1_VALUE *)val,&local_80,(ASN1_ITEM *)PKCS7_ATTR_VERIFY_it);
              if (0 < (int)cnt) {
                iVar3 = EVP_DigestUpdate(&local_78,local_80,cnt);
                if (iVar3 == 0) goto LAB_0817de8f;
                CRYPTO_free(local_80);
LAB_0817df10:
                pAVar1 = si->enc_digest;
                pkey = X509_get_pubkey(x509);
                if (pkey != (EVP_PKEY *)0x0) {
                  iVar3 = EVP_VerifyFinal(&local_78,pAVar1->data,pAVar1->length,pkey);
                  EVP_PKEY_free(pkey);
                  if (0 < iVar3) {
                    iVar8 = 1;
                    goto LAB_0817de91;
                  }
                  iVar5 = 0x471;
                  iVar3 = 0x69;
LAB_0817e071:
                  ERR_put_error(0x21,0x71,iVar3,"pk7_doit.c",iVar5);
                }
                iVar8 = -1;
                goto LAB_0817de91;
              }
              iVar5 = 0x45d;
              iVar3 = 0xd;
              goto LAB_0817e071;
            }
          }
          iVar5 = 0x452;
          iVar3 = 0x65;
          goto LAB_0817e071;
        }
      }
    }
    goto LAB_0817dff3;
  }
  iVar5 = iVar5 + 1;
  goto LAB_0817dfe3;
LAB_0817dff3:
  iVar3 = 0x442;
LAB_0817de7c:
  ERR_put_error(0x21,0x71,0x6c,"pk7_doit.c",iVar3);
LAB_0817de8f:
  iVar8 = 0;
LAB_0817de91:
  EVP_MD_CTX_cleanup(&local_78);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar8;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

