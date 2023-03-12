
undefined4 cms_RecipientInfo_pwri_crypt(int param_1,int param_2,int param_3)

{
  byte bVar1;
  ASN1_OBJECT **ppAVar2;
  char **ppcVar3;
  uint uVar4;
  uint *puVar5;
  uchar *in;
  int iVar6;
  undefined4 uVar7;
  X509_ALGOR *a;
  char *name;
  EVP_CIPHER *cipher;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int in_GS_OFFSET;
  byte bVar13;
  int iVar14;
  int iVar15;
  undefined4 *local_d0;
  uchar *local_b4;
  int local_b0;
  EVP_CIPHER_CTX local_ac;
  int local_20;
  
  bVar13 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_b4 = (uchar *)0x0;
  iVar14 = *(int *)(*(int *)(param_1 + 4) + 0xc);
  iVar15 = *(int *)(param_2 + 4);
  EVP_CIPHER_CTX_init(&local_ac);
  if (*(int *)(iVar15 + 0x10) == 0) {
    iVar15 = 0x157;
    iVar14 = 0xb2;
  }
  else {
    ppAVar2 = *(ASN1_OBJECT ***)(iVar15 + 8);
    if ((ppAVar2 == (ASN1_OBJECT **)0x0) || (iVar6 = OBJ_obj2nid(*ppAVar2), iVar6 != 0x37d)) {
      iVar15 = 0x15f;
      iVar14 = 0xb3;
    }
    else {
      if (ppAVar2[1]->sn == (char *)0x10) {
        ppcVar3 = ppAVar2[1]->ln;
        local_b4 = (uchar *)ppcVar3[2];
        a = d2i_X509_ALGOR((X509_ALGOR **)0x0,&local_b4,(long)*ppcVar3);
        if (a != (X509_ALGOR *)0x0) {
          iVar6 = OBJ_obj2nid(a->algorithm);
          name = OBJ_nid2sn(iVar6);
          cipher = EVP_get_cipherbyname(name);
          if (cipher == (EVP_CIPHER *)0x0) {
            iVar15 = 0x175;
            iVar14 = 0x94;
            goto LAB_08193f62;
          }
          iVar6 = EVP_CipherInit_ex(&local_ac,cipher,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,param_3
                                   );
          if (iVar6 == 0) {
LAB_08193d99:
            uVar7 = 0;
LAB_08193d9b:
            EVP_CIPHER_CTX_cleanup(&local_ac);
          }
          else {
            EVP_CIPHER_CTX_set_padding(&local_ac,0);
            iVar6 = EVP_CIPHER_asn1_to_param(&local_ac,a->parameter);
            if (iVar6 < 0) {
              iVar15 = 0x180;
              iVar14 = 0x66;
LAB_08193f62:
              uVar7 = 0;
              ERR_put_error(0x2e,0xa7,iVar14,"cms_pwri.c",iVar15);
              goto LAB_08193d9b;
            }
            iVar6 = EVP_PBE_CipherInit(**(ASN1_OBJECT ***)(iVar15 + 4),*(char **)(iVar15 + 0x10),
                                       *(int *)(iVar15 + 0x14),
                                       (ASN1_TYPE *)(*(ASN1_OBJECT ***)(iVar15 + 4))[1],&local_ac,
                                       param_3);
            if (iVar6 < 0) {
              iVar15 = 0x18c;
              iVar14 = 6;
              goto LAB_08193f62;
            }
            if (param_3 == 0) {
              local_d0 = (undefined4 *)CRYPTO_malloc(**(int **)(iVar15 + 0xc),"cms_pwri.c",0x1a4);
              if (local_d0 == (undefined4 *)0x0) {
                iVar15 = 0x1a9;
                iVar14 = 0x41;
                goto LAB_08193f62;
              }
              uVar4 = **(uint **)(iVar15 + 0xc);
              in = (uchar *)(*(uint **)(iVar15 + 0xc))[2];
              uVar8 = EVP_CIPHER_CTX_block_size(&local_ac);
              if ((uVar8 * 2 <= uVar4) && (uVar4 % uVar8 == 0)) {
                pbVar10 = (byte *)CRYPTO_malloc(uVar4,"cms_pwri.c",0xf0);
                iVar15 = uVar4 + uVar8 * -2;
                EVP_DecryptUpdate(&local_ac,pbVar10 + iVar15,&local_b0,in + iVar15,uVar8 * 2);
                EVP_DecryptUpdate(&local_ac,pbVar10,&local_b0,pbVar10 + iVar15 + uVar8,uVar8);
                EVP_DecryptUpdate(&local_ac,pbVar10,&local_b0,in,iVar15 + uVar8);
                EVP_DecryptInit_ex(&local_ac,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)0x0,
                                   (uchar *)0x0);
                EVP_DecryptUpdate(&local_ac,pbVar10,&local_b0,pbVar10,uVar4);
                if ((byte)((pbVar10[3] ^ pbVar10[6]) &
                          (pbVar10[2] ^ pbVar10[5]) & (pbVar10[1] ^ pbVar10[4])) == 0xff) {
                  bVar1 = *pbVar10;
                  uVar8 = (uint)bVar1;
                  if (uVar8 - 4 <= uVar4) {
                    if (uVar8 < 4) {
                      if ((uVar8 != 0) && (*(byte *)local_d0 = pbVar10[4], (bVar1 & 2) != 0)) {
                        *(undefined2 *)((int)local_d0 + (uVar8 - 2)) =
                             *(undefined2 *)(pbVar10 + uVar8 + 2);
                      }
                    }
                    else {
                      *local_d0 = *(undefined4 *)(pbVar10 + 4);
                      *(undefined4 *)((int)local_d0 + (uVar8 - 4)) =
                           *(undefined4 *)(pbVar10 + uVar8);
                      iVar15 = (int)local_d0 -
                               (int)(undefined4 *)((uint)(local_d0 + 1) & 0xfffffffc);
                      puVar11 = (undefined4 *)(pbVar10 + (4 - iVar15));
                      puVar12 = (undefined4 *)((uint)(local_d0 + 1) & 0xfffffffc);
                      for (uVar9 = iVar15 + uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
                        *puVar12 = *puVar11;
                        puVar11 = puVar11 + (uint)bVar13 * -2 + 1;
                        puVar12 = puVar12 + (uint)bVar13 * -2 + 1;
                      }
                    }
                    uVar7 = 1;
                    OPENSSL_cleanse(pbVar10,uVar4);
                    CRYPTO_free(pbVar10);
                    *(undefined4 **)(iVar14 + 0x10) = local_d0;
                    *(uint *)(iVar14 + 0x14) = uVar8;
                    goto LAB_08193d9b;
                  }
                }
                OPENSSL_cleanse(pbVar10,uVar4);
                CRYPTO_free(pbVar10);
              }
              ERR_put_error(0x2e,0xa7,0xb4,"cms_pwri.c",0x1b1);
              EVP_CIPHER_CTX_cleanup(&local_ac);
LAB_08194005:
              uVar7 = 0;
              CRYPTO_free(local_d0);
            }
            else {
              uVar4 = *(uint *)(iVar14 + 0x14);
              uVar8 = EVP_CIPHER_CTX_block_size(&local_ac);
              uVar9 = ((uVar4 + 3 + uVar8) / uVar8) * uVar8;
              if ((uVar8 * 2 <= uVar9) && (uVar4 < 0x100)) {
                local_d0 = (undefined4 *)CRYPTO_malloc(uVar9,"cms_pwri.c",0x198);
                if (local_d0 == (undefined4 *)0x0) goto LAB_08193d99;
                pbVar10 = *(byte **)(iVar14 + 0x10);
                uVar4 = *(uint *)(iVar14 + 0x14);
                uVar8 = EVP_CIPHER_CTX_block_size(&local_ac);
                uVar9 = ((uVar8 + 3 + uVar4) / uVar8) * uVar8;
                if ((uVar8 * 2 <= uVar9) && (uVar4 < 0x100)) {
                  *(byte *)local_d0 = (byte)uVar4;
                  *(byte *)((int)local_d0 + 1) = ~*pbVar10;
                  *(byte *)((int)local_d0 + 2) = ~pbVar10[1];
                  *(byte *)((int)local_d0 + 3) = ~pbVar10[2];
                  memcpy(local_d0 + 1,pbVar10,uVar4);
                  uVar8 = uVar4 + 4;
                  if (uVar8 <= uVar9 && uVar9 - uVar8 != 0) {
                    RAND_pseudo_bytes((byte *)(uVar8 + (int)local_d0),(uVar9 - uVar4) + -4);
                  }
                  EVP_EncryptUpdate(&local_ac,(uchar *)local_d0,&local_b0,(uchar *)local_d0,uVar9);
                  EVP_EncryptUpdate(&local_ac,(uchar *)local_d0,&local_b0,(uchar *)local_d0,uVar9);
                  puVar5 = *(uint **)(iVar15 + 0xc);
                  uVar7 = 1;
                  puVar5[2] = (uint)local_d0;
                  *puVar5 = uVar9;
                  goto LAB_08193d9b;
                }
                EVP_CIPHER_CTX_cleanup(&local_ac);
                goto LAB_08194005;
              }
              uVar7 = 0;
              EVP_CIPHER_CTX_cleanup(&local_ac);
            }
          }
          X509_ALGOR_free(a);
          goto LAB_08193cee;
        }
      }
      iVar15 = 0x16c;
      iVar14 = 0xb0;
    }
  }
  ERR_put_error(0x2e,0xa7,iVar14,"cms_pwri.c",iVar15);
  uVar7 = 0;
LAB_08193cee:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}

