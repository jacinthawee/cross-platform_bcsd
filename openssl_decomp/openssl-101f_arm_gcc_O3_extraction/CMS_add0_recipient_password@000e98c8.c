
CMS_RecipientInfo *
CMS_add0_recipient_password
          (CMS_ContentInfo *cms,int iter,int wrap_nid,int pbe_nid,uchar *pass,ssize_t passlen,
          EVP_CIPHER *kekciph)

{
  EVP_CIPHER *pEVar1;
  EVP_CIPHER *a;
  int iVar2;
  ASN1_TYPE *pAVar3;
  EVP_CIPHER *ctx;
  ASN1_OBJECT *pAVar4;
  X509_ALGOR *pXVar5;
  ASN1_TYPE *pAVar6;
  ASN1_STRING *pAVar7;
  _STACK *st;
  int iVar8;
  uint uVar9;
  uchar auStack_c8 [16];
  EVP_CIPHER_CTX EStack_b8;
  int local_2c;
  
  local_2c = __TMC_END__;
  pEVar1 = (EVP_CIPHER *)cms_get0_enveloped();
  a = pEVar1;
  if (pEVar1 == (EVP_CIPHER *)0x0) goto LAB_000e9a92;
  if (wrap_nid < 1) {
    wrap_nid = 0x37d;
  }
  if ((kekciph == (EVP_CIPHER *)0x0) &&
     (kekciph = *(EVP_CIPHER **)(pEVar1->iv_len + 0xc), kekciph == (EVP_CIPHER *)0x0)) {
    ERR_put_error(0x2e,0xa5,0x7e,"cms_pwri.c",0x70);
    goto LAB_000e9aa8;
  }
  if (wrap_nid != 0x37d) {
    ERR_put_error(0x2e,0xa5,0xb3,"cms_pwri.c",0x76);
    kekciph = (EVP_CIPHER *)0x0;
    goto LAB_000e9aa8;
  }
  a = (EVP_CIPHER *)X509_ALGOR_new();
  EVP_CIPHER_CTX_init(&EStack_b8);
  iVar2 = EVP_EncryptInit_ex(&EStack_b8,kekciph,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0);
  if (iVar2 < 1) {
    iVar2 = 0x80;
LAB_000e9abc:
    ERR_put_error(0x2e,0xa5,6,"cms_pwri.c",iVar2);
LAB_000e9a92:
    kekciph = a;
    EVP_CIPHER_CTX_cleanup(&EStack_b8);
LAB_000e9a98:
    a = kekciph;
    if (kekciph == (EVP_CIPHER *)0x0) goto LAB_000e9aa8;
  }
  else {
    iVar2 = EVP_CIPHER_CTX_iv_length(&EStack_b8);
    if (0 < iVar2) {
      iVar2 = RAND_pseudo_bytes(auStack_c8,iVar2);
      if (0 < iVar2) {
        iVar2 = EVP_EncryptInit_ex(&EStack_b8,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)0x0,
                                   auStack_c8);
        if (iVar2 < 1) {
          iVar2 = 0x8d;
          goto LAB_000e9abc;
        }
        pAVar3 = ASN1_TYPE_new();
        a->block_size = (int)pAVar3;
        if (pAVar3 == (ASN1_TYPE *)0x0) {
          ERR_put_error(0x2e,0xa5,0x41,"cms_pwri.c",0x94);
        }
        else {
          iVar2 = EVP_CIPHER_param_to_asn1(&EStack_b8,pAVar3);
          if (0 < iVar2) goto LAB_000e997e;
          ERR_put_error(0x2e,0xa5,0x66,"cms_pwri.c",0x9a);
        }
      }
      goto LAB_000e9a92;
    }
LAB_000e997e:
    ctx = EVP_CIPHER_CTX_cipher(&EStack_b8);
    iVar2 = EVP_CIPHER_type(ctx);
    pAVar4 = OBJ_nid2obj(iVar2);
    a->nid = (int)pAVar4;
    EVP_CIPHER_CTX_cleanup(&EStack_b8);
    kekciph = (EVP_CIPHER *)ASN1_item_new((ASN1_ITEM *)CMS_RecipientInfo_it);
    if (kekciph != (EVP_CIPHER *)0x0) {
      pAVar3 = (ASN1_TYPE *)ASN1_item_new((ASN1_ITEM *)CMS_PasswordRecipientInfo_it);
      kekciph->block_size = (int)pAVar3;
      if (pAVar3 == (ASN1_TYPE *)0x0) {
LAB_000e9ae8:
        ERR_put_error(0x2e,0xa5,0x41,"cms_pwri.c",0xd1);
        EVP_CIPHER_CTX_cleanup(&EStack_b8);
      }
      else {
        pXVar5 = (X509_ALGOR *)pAVar3[1].type;
        kekciph->nid = 3;
        X509_ALGOR_free(pXVar5);
        pXVar5 = X509_ALGOR_new();
        pAVar3[1].type = (int)pXVar5;
        if (pXVar5 == (X509_ALGOR *)0x0) goto LAB_000e9ae8;
        pAVar4 = OBJ_nid2obj(0x37d);
        iVar2 = pAVar3[1].type;
        pXVar5->algorithm = pAVar4;
        pAVar6 = ASN1_TYPE_new();
        iVar8 = pAVar3[1].type;
        *(ASN1_TYPE **)(iVar2 + 4) = pAVar6;
        iVar2 = *(int *)(iVar8 + 4);
        if ((iVar2 == 0) ||
           (pAVar7 = ASN1_item_pack(a,(ASN1_ITEM *)&X509_ALGOR_it,(ASN1_OCTET_STRING **)(iVar2 + 4))
           , pAVar7 == (ASN1_STRING *)0x0)) goto LAB_000e9ae8;
        **(undefined4 **)(pAVar3[1].type + 4) = 0x10;
        X509_ALGOR_free((X509_ALGOR *)a);
        a = (EVP_CIPHER *)PKCS5_pbkdf2_set(iter,(uchar *)0x0,0,-1,-1);
        (pAVar3->value).asn1_string = (ASN1_STRING *)a;
        if (a != (EVP_CIPHER *)0x0) {
          if ((ASN1_OBJECT *)kekciph->nid == (ASN1_OBJECT *)0x3) {
            pAVar6 = (ASN1_TYPE *)kekciph->block_size;
            uVar9 = (uint)passlen >> 0x1f;
            if (pass == (uchar *)0x0) {
              uVar9 = 0;
            }
            pAVar6[2].type = (int)pass;
            if (uVar9 != 0) {
              passlen = strlen((char *)pass);
            }
            pAVar6[2].value.boolean = passlen;
          }
          else {
            ERR_put_error(0x2e,0xa8,0xb1,"cms_pwri.c",0x47);
          }
          st = (_STACK *)pEVar1->key_len;
          pAVar3->type = 0;
          a = (EVP_CIPHER *)sk_push(st,kekciph);
          if (a != (EVP_CIPHER *)0x0) goto LAB_000e9aa8;
          goto LAB_000e9ae8;
        }
        EVP_CIPHER_CTX_cleanup(&EStack_b8);
      }
      ASN1_item_free((ASN1_VALUE *)kekciph,(ASN1_ITEM *)CMS_RecipientInfo_it);
      kekciph = a;
      goto LAB_000e9a98;
    }
    ERR_put_error(0x2e,0xa5,0x41,"cms_pwri.c",0xd1);
    EVP_CIPHER_CTX_cleanup(&EStack_b8);
  }
  X509_ALGOR_free((X509_ALGOR *)a);
  kekciph = (EVP_CIPHER *)0x0;
LAB_000e9aa8:
  if (local_2c == __TMC_END__) {
    return (CMS_RecipientInfo *)kekciph;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

