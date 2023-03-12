
CMS_RecipientInfo *
CMS_add0_recipient_password
          (CMS_ContentInfo *cms,int iter,int wrap_nid,int pbe_nid,uchar *pass,ssize_t passlen,
          EVP_CIPHER *kekciph)

{
  int iVar1;
  X509_ALGOR *pXVar2;
  int iVar3;
  ASN1_TYPE *pAVar4;
  EVP_CIPHER *ctx;
  ASN1_OBJECT *pAVar5;
  int *val;
  undefined4 *puVar6;
  X509_ALGOR *pXVar7;
  ASN1_STRING *pAVar8;
  int in_GS_OFFSET;
  EVP_CIPHER_CTX local_bc;
  uchar local_30 [16];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = cms_get0_enveloped(cms);
  if (iVar1 == 0) {
    pXVar2 = (X509_ALGOR *)0x0;
    goto LAB_08193ace;
  }
  if (wrap_nid < 1) {
    if ((kekciph != (EVP_CIPHER *)0x0) ||
       (kekciph = *(EVP_CIPHER **)(*(int *)(iVar1 + 0xc) + 0xc), kekciph != (EVP_CIPHER *)0x0)) {
LAB_08193837:
      pXVar2 = X509_ALGOR_new();
      EVP_CIPHER_CTX_init(&local_bc);
      iVar3 = EVP_EncryptInit_ex(&local_bc,kekciph,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0);
      if (iVar3 < 1) {
        iVar1 = 0x80;
LAB_08193ab8:
        ERR_put_error(0x2e,0xa5,6,"cms_pwri.c",iVar1);
LAB_08193ace:
        EVP_CIPHER_CTX_cleanup(&local_bc);
LAB_08193ada:
        val = (int *)0x0;
        if (pXVar2 == (X509_ALGOR *)0x0) goto LAB_08193a90;
      }
      else {
        iVar3 = EVP_CIPHER_CTX_iv_length(&local_bc);
        if (0 < iVar3) {
          iVar3 = RAND_pseudo_bytes(local_30,iVar3);
          if (0 < iVar3) {
            iVar3 = EVP_EncryptInit_ex(&local_bc,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)0x0,
                                       local_30);
            if (iVar3 < 1) {
              iVar1 = 0x8d;
              goto LAB_08193ab8;
            }
            pAVar4 = ASN1_TYPE_new();
            pXVar2->parameter = pAVar4;
            if (pAVar4 == (ASN1_TYPE *)0x0) {
              ERR_put_error(0x2e,0xa5,0x41,"cms_pwri.c",0x94);
            }
            else {
              iVar3 = EVP_CIPHER_param_to_asn1(&local_bc,pAVar4);
              if (0 < iVar3) goto LAB_081938d4;
              ERR_put_error(0x2e,0xa5,0x66,"cms_pwri.c",0x9a);
            }
          }
          goto LAB_08193ace;
        }
LAB_081938d4:
        ctx = EVP_CIPHER_CTX_cipher(&local_bc);
        iVar3 = EVP_CIPHER_type(ctx);
        pAVar5 = OBJ_nid2obj(iVar3);
        pXVar2->algorithm = pAVar5;
        EVP_CIPHER_CTX_cleanup(&local_bc);
        val = (int *)ASN1_item_new((ASN1_ITEM *)CMS_RecipientInfo_it);
        if (val != (int *)0x0) {
          puVar6 = (undefined4 *)ASN1_item_new((ASN1_ITEM *)CMS_PasswordRecipientInfo_it);
          val[1] = (int)puVar6;
          if (puVar6 == (undefined4 *)0x0) {
LAB_08193b20:
            ERR_put_error(0x2e,0xa5,0x41,"cms_pwri.c",0xd1);
            EVP_CIPHER_CTX_cleanup(&local_bc);
          }
          else {
            *val = 3;
            X509_ALGOR_free((X509_ALGOR *)puVar6[2]);
            pXVar7 = X509_ALGOR_new();
            puVar6[2] = pXVar7;
            if (pXVar7 == (X509_ALGOR *)0x0) goto LAB_08193b20;
            pAVar5 = OBJ_nid2obj(0x37d);
            pXVar7->algorithm = pAVar5;
            iVar3 = puVar6[2];
            pAVar4 = ASN1_TYPE_new();
            *(ASN1_TYPE **)(iVar3 + 4) = pAVar4;
            if ((*(int *)(puVar6[2] + 4) == 0) ||
               (pAVar8 = ASN1_item_pack(pXVar2,(ASN1_ITEM *)X509_ALGOR_it,
                                        (ASN1_OCTET_STRING **)(*(int *)(puVar6[2] + 4) + 4)),
               pAVar8 == (ASN1_STRING *)0x0)) goto LAB_08193b20;
            **(undefined4 **)(puVar6[2] + 4) = 0x10;
            X509_ALGOR_free(pXVar2);
            pXVar2 = PKCS5_pbkdf2_set(iter,(uchar *)0x0,0,-1,-1);
            puVar6[1] = pXVar2;
            if (pXVar2 != (X509_ALGOR *)0x0) {
              if (*val == 3) {
                iVar3 = val[1];
                *(uchar **)(iVar3 + 0x10) = pass;
                if ((pass != (uchar *)0x0) && (passlen < 0)) {
                  passlen = strlen((char *)pass);
                }
                *(ssize_t *)(iVar3 + 0x14) = passlen;
              }
              else {
                ERR_put_error(0x2e,0xa8,0xb1,"cms_pwri.c",0x47);
              }
              *puVar6 = 0;
              pXVar2 = (X509_ALGOR *)0x0;
              iVar1 = sk_push(*(_STACK **)(iVar1 + 8),val);
              if (iVar1 != 0) goto LAB_08193a90;
              goto LAB_08193b20;
            }
            pXVar2 = (X509_ALGOR *)0x0;
            EVP_CIPHER_CTX_cleanup(&local_bc);
          }
          ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)CMS_RecipientInfo_it);
          goto LAB_08193ada;
        }
        ERR_put_error(0x2e,0xa5,0x41,"cms_pwri.c",0xd1);
        EVP_CIPHER_CTX_cleanup(&local_bc);
      }
      X509_ALGOR_free(pXVar2);
      val = (int *)0x0;
      goto LAB_08193a90;
    }
LAB_08193b06:
    iVar3 = 0x70;
    iVar1 = 0x7e;
  }
  else {
    if ((kekciph == (EVP_CIPHER *)0x0) &&
       (kekciph = *(EVP_CIPHER **)(*(int *)(iVar1 + 0xc) + 0xc), kekciph == (EVP_CIPHER *)0x0))
    goto LAB_08193b06;
    if (wrap_nid == 0x37d) goto LAB_08193837;
    iVar3 = 0x76;
    iVar1 = 0xb3;
  }
  ERR_put_error(0x2e,0xa5,iVar1,"cms_pwri.c",iVar3);
  val = (int *)0x0;
LAB_08193a90:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (CMS_RecipientInfo *)val;
}

