
CMS_RecipientInfo *
CMS_add0_recipient_password
          (CMS_ContentInfo *cms,int iter,int wrap_nid,int pbe_nid,uchar *pass,ssize_t passlen,
          EVP_CIPHER *kekciph)

{
  int iVar1;
  X509_ALGOR *a;
  int iVar2;
  ASN1_TYPE *pAVar3;
  EVP_CIPHER *ctx;
  ASN1_OBJECT *pAVar4;
  undefined4 *puVar5;
  X509_ALGOR *pXVar6;
  ASN1_STRING *pAVar7;
  _STACK *st;
  int iVar8;
  uint uVar9;
  uchar auStack_c8 [16];
  EVP_CIPHER_CTX EStack_b8;
  int local_2c;
  
  local_2c = __stack_chk_guard;
  iVar1 = cms_get0_enveloped();
  if (iVar1 != 0) {
    if (wrap_nid < 1) {
      wrap_nid = 0x37d;
    }
    if ((kekciph == (EVP_CIPHER *)0x0) &&
       (kekciph = *(EVP_CIPHER **)(*(int *)(iVar1 + 0xc) + 0xc), kekciph == (EVP_CIPHER *)0x0)) {
      ERR_put_error(0x2e,0xa5,0x7e,"cms_pwri.c",0x71);
      goto LAB_000e7b46;
    }
    if (wrap_nid != 0x37d) {
      ERR_put_error(0x2e,0xa5,0xb3,"cms_pwri.c",0x76);
      kekciph = (EVP_CIPHER *)0x0;
      goto LAB_000e7b46;
    }
    a = X509_ALGOR_new();
    if (a == (X509_ALGOR *)0x0) {
LAB_000e7b6e:
      ERR_put_error(0x2e,0xa5,0x41,"cms_pwri.c",0xcd);
      EVP_CIPHER_CTX_cleanup(&EStack_b8);
joined_r0x000e7b8c:
      if (a == (X509_ALGOR *)0x0) goto LAB_000e7b44;
    }
    else {
      EVP_CIPHER_CTX_init(&EStack_b8);
      iVar2 = EVP_EncryptInit_ex(&EStack_b8,kekciph,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0);
      if (iVar2 < 1) {
        iVar1 = 0x82;
LAB_000e7b28:
        ERR_put_error(0x2e,0xa5,6,"cms_pwri.c",iVar1);
      }
      else {
        iVar2 = EVP_CIPHER_CTX_iv_length(&EStack_b8);
        if (iVar2 < 1) {
LAB_000e7a1e:
          ctx = EVP_CIPHER_CTX_cipher(&EStack_b8);
          iVar2 = EVP_CIPHER_type(ctx);
          pAVar4 = OBJ_nid2obj(iVar2);
          a->algorithm = pAVar4;
          EVP_CIPHER_CTX_cleanup(&EStack_b8);
          kekciph = (EVP_CIPHER *)ASN1_item_new((ASN1_ITEM *)CMS_RecipientInfo_it);
          if (kekciph == (EVP_CIPHER *)0x0) goto LAB_000e7b6e;
          puVar5 = (undefined4 *)ASN1_item_new((ASN1_ITEM *)CMS_PasswordRecipientInfo_it);
          kekciph->block_size = (int)puVar5;
          if (puVar5 == (undefined4 *)0x0) {
LAB_000e7b90:
            ERR_put_error(0x2e,0xa5,0x41,"cms_pwri.c",0xcd);
          }
          else {
            pXVar6 = (X509_ALGOR *)puVar5[2];
            kekciph->nid = 3;
            X509_ALGOR_free(pXVar6);
            pXVar6 = X509_ALGOR_new();
            puVar5[2] = pXVar6;
            if (pXVar6 == (X509_ALGOR *)0x0) goto LAB_000e7b90;
            pAVar4 = OBJ_nid2obj(0x37d);
            iVar2 = puVar5[2];
            pXVar6->algorithm = pAVar4;
            pAVar3 = ASN1_TYPE_new();
            iVar8 = puVar5[2];
            *(ASN1_TYPE **)(iVar2 + 4) = pAVar3;
            if ((*(int *)(iVar8 + 4) == 0) ||
               (pAVar7 = ASN1_item_pack(a,(ASN1_ITEM *)&X509_ALGOR_it,
                                        (ASN1_OCTET_STRING **)(*(int *)(iVar8 + 4) + 4)),
               pAVar7 == (ASN1_STRING *)0x0)) goto LAB_000e7b90;
            **(undefined4 **)(puVar5[2] + 4) = 0x10;
            X509_ALGOR_free(a);
            a = PKCS5_pbkdf2_set(iter,(uchar *)0x0,0,-1,-1);
            puVar5[1] = a;
            if (a != (X509_ALGOR *)0x0) {
              if (kekciph->nid == 3) {
                iVar2 = kekciph->block_size;
                uVar9 = (uint)passlen >> 0x1f;
                if (pass == (uchar *)0x0) {
                  uVar9 = 0;
                }
                *(uchar **)(iVar2 + 0x10) = pass;
                if (uVar9 != 0) {
                  passlen = strlen((char *)pass);
                }
                *(ssize_t *)(iVar2 + 0x14) = passlen;
              }
              else {
                ERR_put_error(0x2e,0xa8,0xb1,"cms_pwri.c",0x47);
              }
              st = *(_STACK **)(iVar1 + 8);
              *puVar5 = 0;
              a = (X509_ALGOR *)sk_push(st,kekciph);
              if (a != (X509_ALGOR *)0x0) goto LAB_000e7b46;
              goto LAB_000e7b90;
            }
          }
          EVP_CIPHER_CTX_cleanup(&EStack_b8);
          ASN1_item_free((ASN1_VALUE *)kekciph,(ASN1_ITEM *)CMS_RecipientInfo_it);
          goto joined_r0x000e7b8c;
        }
        iVar2 = RAND_bytes(auStack_c8,iVar2);
        if (0 < iVar2) {
          iVar2 = EVP_EncryptInit_ex(&EStack_b8,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)0x0,
                                     auStack_c8);
          if (iVar2 < 1) {
            iVar1 = 0x8c;
            goto LAB_000e7b28;
          }
          pAVar3 = ASN1_TYPE_new();
          a->parameter = pAVar3;
          if (pAVar3 == (ASN1_TYPE *)0x0) {
            ERR_put_error(0x2e,0xa5,0x41,"cms_pwri.c",0x91);
          }
          else {
            iVar2 = EVP_CIPHER_param_to_asn1(&EStack_b8,pAVar3);
            if (0 < iVar2) goto LAB_000e7a1e;
            ERR_put_error(0x2e,0xa5,0x66,"cms_pwri.c",0x96);
          }
        }
      }
      EVP_CIPHER_CTX_cleanup(&EStack_b8);
    }
    X509_ALGOR_free(a);
  }
LAB_000e7b44:
  kekciph = (EVP_CIPHER *)0x0;
LAB_000e7b46:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (CMS_RecipientInfo *)kekciph;
}

