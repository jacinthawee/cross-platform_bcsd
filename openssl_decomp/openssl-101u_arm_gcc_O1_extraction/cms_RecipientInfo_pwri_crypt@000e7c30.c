
void cms_RecipientInfo_pwri_crypt(int param_1,int param_2,int param_3)

{
  int iVar1;
  X509_ALGOR *a;
  char *name;
  EVP_CIPHER *cipher;
  int iVar2;
  int extraout_r1;
  uchar *in;
  char **ppcVar3;
  uint *puVar4;
  int iVar5;
  EVP_CIPHER *pEVar6;
  ASN1_OBJECT **ppAVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  uchar *local_c0;
  int iStack_bc;
  EVP_CIPHER_CTX EStack_b8;
  int local_2c;
  
  iVar8 = *(int *)(param_2 + 4);
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 0xc);
  local_c0 = (uchar *)0x0;
  local_2c = __stack_chk_guard;
  EVP_CIPHER_CTX_init(&EStack_b8);
  pEVar6 = *(EVP_CIPHER **)(iVar8 + 0x10);
  if (pEVar6 == (EVP_CIPHER *)0x0) {
    ERR_put_error(0x2e,0xa7,0xb2,"cms_pwri.c",0x152);
    goto LAB_000e7c8e;
  }
  ppAVar7 = *(ASN1_OBJECT ***)(iVar8 + 8);
  if ((ppAVar7 == (ASN1_OBJECT **)0x0) || (iVar1 = OBJ_obj2nid(*ppAVar7), iVar1 != 0x37d)) {
    ERR_put_error(0x2e,0xa7,0xb3,"cms_pwri.c",0x159);
    pEVar6 = (EVP_CIPHER *)0x0;
    goto LAB_000e7c8e;
  }
  if (ppAVar7[1]->sn == (char *)0x10) {
    ppcVar3 = ppAVar7[1]->ln;
    local_c0 = (uchar *)ppcVar3[2];
    a = d2i_X509_ALGOR((X509_ALGOR **)0x0,&local_c0,(long)*ppcVar3);
    if (a != (X509_ALGOR *)0x0) {
      iVar1 = OBJ_obj2nid(a->algorithm);
      name = OBJ_nid2sn(iVar1);
      cipher = EVP_get_cipherbyname(name);
      if (cipher == (EVP_CIPHER *)0x0) {
        ERR_put_error(0x2e,0xa7,0x94,"cms_pwri.c",0x16b);
LAB_000e7d08:
        EVP_CIPHER_CTX_cleanup(&EStack_b8);
        pEVar6 = cipher;
      }
      else {
        iVar1 = EVP_CipherInit_ex(&EStack_b8,cipher,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,param_3)
        ;
        if (iVar1 == 0) {
LAB_000e7d04:
          cipher = (EVP_CIPHER *)0x0;
          goto LAB_000e7d08;
        }
        EVP_CIPHER_CTX_set_padding(&EStack_b8,0);
        iVar1 = EVP_CIPHER_asn1_to_param(&EStack_b8,a->parameter);
        if (iVar1 < 0) {
          cipher = (EVP_CIPHER *)0x0;
          ERR_put_error(0x2e,0xa7,0x66,"cms_pwri.c",0x175);
          goto LAB_000e7d08;
        }
        iVar1 = EVP_PBE_CipherInit(**(ASN1_OBJECT ***)(iVar8 + 4),*(char **)(iVar8 + 0x10),
                                   *(int *)(iVar8 + 0x14),
                                   (ASN1_TYPE *)(*(ASN1_OBJECT ***)(iVar8 + 4))[1],&EStack_b8,
                                   param_3);
        if (iVar1 < 0) {
          cipher = (EVP_CIPHER *)0x0;
          ERR_put_error(0x2e,0xa7,6,"cms_pwri.c",0x180);
          goto LAB_000e7d08;
        }
        if (param_3 == 0) {
          cipher = (EVP_CIPHER *)CRYPTO_malloc(**(int **)(iVar8 + 0xc),"cms_pwri.c",0x195);
          if (cipher == (EVP_CIPHER *)0x0) {
            ERR_put_error(0x2e,0xa7,0x41,"cms_pwri.c",0x198);
            goto LAB_000e7d08;
          }
          in = (uchar *)(*(uint **)(iVar8 + 0xc))[2];
          uVar9 = **(uint **)(iVar8 + 0xc);
          iVar8 = EVP_CIPHER_CTX_block_size(&EStack_b8);
          if (((uint)(iVar8 * 2) <= uVar9) && (__aeabi_uidivmod(uVar9,iVar8), extraout_r1 == 0)) {
            pbVar11 = (byte *)CRYPTO_malloc(uVar9,"cms_pwri.c",0xec);
            if (pbVar11 != (byte *)0x0) {
              iVar1 = uVar9 + iVar8 * -2;
              EVP_DecryptUpdate(&EStack_b8,pbVar11 + iVar1,&iStack_bc,in + iVar1,iVar8 * 2);
              EVP_DecryptUpdate(&EStack_b8,pbVar11,&iStack_bc,pbVar11 + iVar8 + iVar1,iVar8);
              EVP_DecryptUpdate(&EStack_b8,pbVar11,&iStack_bc,in,iVar8 + iVar1);
              EVP_DecryptInit_ex(&EStack_b8,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)0x0,
                                 (uchar *)0x0);
              EVP_DecryptUpdate(&EStack_b8,pbVar11,&iStack_bc,pbVar11,uVar9);
              if (((byte)((pbVar11[3] ^ pbVar11[6]) &
                         (pbVar11[4] ^ pbVar11[1]) & (pbVar11[5] ^ pbVar11[2])) == 0xff) &&
                 (uVar10 = (uint)*pbVar11, uVar10 - 4 <= uVar9)) {
                memcpy(cipher,pbVar11 + 4,uVar10);
                OPENSSL_cleanse(pbVar11,uVar9);
                CRYPTO_free(pbVar11);
                *(EVP_CIPHER **)(iVar5 + 0x10) = cipher;
                *(uint *)(iVar5 + 0x14) = uVar10;
                cipher = (EVP_CIPHER *)0x1;
                goto LAB_000e7d08;
              }
              OPENSSL_cleanse(pbVar11,uVar9);
              CRYPTO_free(pbVar11);
            }
          }
          ERR_put_error(0x2e,0xa7,0xb4,"cms_pwri.c",0x19e);
        }
        else {
          uVar9 = *(uint *)(iVar5 + 0x14);
          iVar1 = EVP_CIPHER_CTX_block_size(&EStack_b8);
          iVar2 = __udivsi3(uVar9 + 3 + iVar1,iVar1);
          if ((((uint)(iVar1 * iVar2) < (uint)(iVar1 << 1)) || (0xff < uVar9)) ||
             (cipher = (EVP_CIPHER *)CRYPTO_malloc(iVar1 * iVar2,"cms_pwri.c",0x18b),
             cipher == (EVP_CIPHER *)0x0)) goto LAB_000e7d04;
          uVar9 = *(uint *)(iVar5 + 0x14);
          pbVar11 = *(byte **)(iVar5 + 0x10);
          iVar5 = EVP_CIPHER_CTX_block_size(&EStack_b8);
          iVar1 = __udivsi3(uVar9 + 3 + iVar5,iVar5);
          uVar10 = iVar5 * iVar1;
          if (((uint)(iVar5 << 1) <= uVar10) && (uVar9 < 0x100)) {
            *(char *)&cipher->nid = (char)uVar9;
            *(byte *)((int)&cipher->nid + 1) = ~*pbVar11;
            *(byte *)((int)&cipher->nid + 2) = ~pbVar11[1];
            *(byte *)((int)&cipher->nid + 3) = ~pbVar11[2];
            memcpy(&cipher->block_size,pbVar11,uVar9);
            if ((uVar10 < uVar9 + 4 || uVar10 - (uVar9 + 4) == 0) ||
               (iVar5 = RAND_bytes((uchar *)((int)&cipher->block_size + uVar9),(-4 - uVar9) + uVar10
                                  ), 0 < iVar5)) {
              EVP_EncryptUpdate(&EStack_b8,(uchar *)cipher,&iStack_bc,(uchar *)cipher,uVar10);
              EVP_EncryptUpdate(&EStack_b8,(uchar *)cipher,&iStack_bc,(uchar *)cipher,uVar10);
              puVar4 = *(uint **)(iVar8 + 0xc);
              puVar4[2] = (uint)cipher;
              *puVar4 = uVar10;
              cipher = (EVP_CIPHER *)0x1;
              goto LAB_000e7d08;
            }
          }
        }
        pEVar6 = (EVP_CIPHER *)0x0;
        EVP_CIPHER_CTX_cleanup(&EStack_b8);
        CRYPTO_free(cipher);
      }
      X509_ALGOR_free(a);
      goto LAB_000e7c8e;
    }
  }
  ERR_put_error(0x2e,0xa7,0xb0,"cms_pwri.c",0x164);
  pEVar6 = (EVP_CIPHER *)0x0;
LAB_000e7c8e:
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pEVar6);
}

