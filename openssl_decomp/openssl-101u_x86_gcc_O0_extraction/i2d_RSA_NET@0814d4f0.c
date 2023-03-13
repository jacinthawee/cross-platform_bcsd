
int i2d_RSA_NET(RSA *a,uchar **pp,cb *cb,int sgckey)

{
  ASN1_OBJECT **ppAVar1;
  ASN1_STRING *pAVar2;
  int iVar3;
  undefined4 *val;
  ASN1_STRING **val_00;
  ASN1_OBJECT *pAVar4;
  ASN1_TYPE *pAVar5;
  size_t sVar6;
  int iVar7;
  code *pcVar8;
  uint uVar9;
  uint uVar10;
  EVP_MD *pEVar11;
  EVP_CIPHER *pEVar12;
  uint *puVar13;
  uint *puVar14;
  int in_GS_OFFSET;
  bool bVar15;
  int iVar16;
  size_t local_1f8;
  int local_1f4;
  uchar *local_1f0;
  EVP_CIPHER_CTX local_1ec;
  uchar local_160 [64];
  uint local_120 [4];
  undefined4 local_110;
  undefined4 local_10c;
  undefined2 local_108;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_CIPHER_CTX_init(&local_1ec);
  iVar3 = 0;
  if (a == (RSA *)0x0) goto LAB_0814d70c;
  val = (undefined4 *)ASN1_item_new((ASN1_ITEM *)NETSCAPE_PKEY_it);
  if (val == (undefined4 *)0x0) {
LAB_0814d6e0:
    val_00 = (ASN1_STRING **)0x0;
    iVar3 = 0;
  }
  else {
    val_00 = (ASN1_STRING **)ASN1_item_new((ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
    if (val_00 == (ASN1_STRING **)0x0) goto LAB_0814d6e0;
    ppAVar1 = (ASN1_OBJECT **)val[1];
    *val = 0;
    pAVar4 = OBJ_nid2obj(6);
    *ppAVar1 = pAVar4;
    iVar3 = val[1];
    pAVar5 = ASN1_TYPE_new();
    *(ASN1_TYPE **)(iVar3 + 4) = pAVar5;
    if (pAVar5 == (ASN1_TYPE *)0x0) {
LAB_0814d730:
      iVar3 = 0;
    }
    else {
      **(undefined4 **)(val[1] + 4) = 5;
      sVar6 = i2d_RSAPrivateKey(a,(uchar **)0x0);
      *(size_t *)val[2] = sVar6;
      iVar7 = ASN1_item_i2d((ASN1_VALUE *)val,(uchar **)0x0,(ASN1_ITEM *)NETSCAPE_PKEY_it);
      pAVar2 = val_00[1];
      *(int *)pAVar2->type = iVar7;
      (*val_00)->length = 0xb;
      ppAVar1 = (ASN1_OBJECT **)pAVar2->length;
      pAVar4 = OBJ_nid2obj(5);
      *ppAVar1 = pAVar4;
      iVar3 = val_00[1]->length;
      pAVar5 = ASN1_TYPE_new();
      *(ASN1_TYPE **)(iVar3 + 4) = pAVar5;
      if (pAVar5 == (ASN1_TYPE *)0x0) goto LAB_0814d730;
      **(undefined4 **)(val_00[1]->length + 4) = 5;
      if (pp == (uchar **)0x0) {
        iVar3 = ASN1_item_i2d((ASN1_VALUE *)val_00,(uchar **)0x0,
                              (ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
        ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)NETSCAPE_PKEY_it);
        ASN1_item_free((ASN1_VALUE *)val_00,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
        goto LAB_0814d70c;
      }
      local_1f0 = (uchar *)CRYPTO_malloc(sVar6,"n_pkey.c",0xab);
      if (local_1f0 == (uchar *)0x0) {
        iVar16 = 0xac;
        iVar7 = 0x41;
LAB_0814d6cb:
        iVar3 = 0;
        ERR_put_error(0xd,0xa2,iVar7,"n_pkey.c",iVar16);
      }
      else {
        *(uchar **)(val[2] + 8) = local_1f0;
        i2d_RSAPrivateKey(a,&local_1f0);
        local_1f0 = (uchar *)CRYPTO_malloc(iVar7,"n_pkey.c",0xb4);
        if (local_1f0 == (uchar *)0x0) {
          iVar16 = 0xb5;
          iVar7 = 0x41;
          goto LAB_0814d6cb;
        }
        iVar3 = ASN1_STRING_set(*val_00,"private-key",-1);
        if (iVar3 == 0) {
          iVar16 = 0xba;
          iVar7 = 0x41;
          goto LAB_0814d6cb;
        }
        *(uchar **)(val_00[1]->type + 8) = local_1f0;
        ASN1_item_i2d((ASN1_VALUE *)val,&local_1f0,(ASN1_ITEM *)NETSCAPE_PKEY_it);
        OPENSSL_cleanse(*(void **)(val[2] + 8),sVar6);
        pcVar8 = EVP_read_pw_string;
        if (cb != (cb *)0x0) {
          pcVar8 = cb;
        }
        local_1f8 = (*pcVar8)((char *)local_120,0x100,"Enter Private Key password:",1);
        puVar14 = local_120;
        if (local_1f8 != 0) {
          iVar16 = 199;
          iVar7 = 0x67;
          goto LAB_0814d6cb;
        }
        do {
          puVar13 = puVar14;
          uVar9 = *puVar13 + 0xfefefeff & ~*puVar13;
          uVar10 = uVar9 & 0x80808080;
          puVar14 = puVar13 + 1;
        } while (uVar10 == 0);
        bVar15 = (uVar9 & 0x8080) == 0;
        if (bVar15) {
          uVar10 = uVar10 >> 0x10;
        }
        if (bVar15) {
          puVar14 = (uint *)((int)puVar13 + 6);
        }
        local_1f8 = (int)puVar14 + ((-3 - (uint)CARRY1((byte)uVar10,(byte)uVar10)) - (int)local_120)
        ;
        if (sgckey == 0) {
LAB_0814d853:
          sVar6 = local_1f8;
          pEVar11 = EVP_md5();
          pEVar12 = EVP_rc4();
          iVar3 = 0;
          iVar16 = EVP_BytesToKey(pEVar12,pEVar11,(uchar *)0x0,(uchar *)local_120,sVar6,1,local_160,
                                  (uchar *)0x0);
          if (iVar16 != 0) {
            OPENSSL_cleanse(local_120,0x100);
            local_1f0 = *(uchar **)(val_00[1]->type + 8);
            pEVar12 = EVP_rc4();
            iVar16 = EVP_EncryptInit_ex(&local_1ec,pEVar12,(ENGINE *)0x0,local_160,(uchar *)0x0);
            if (iVar16 != 0) {
              iVar7 = EVP_EncryptUpdate(&local_1ec,local_1f0,(int *)&local_1f8,local_1f0,iVar7);
              if (iVar7 != 0) {
                iVar7 = EVP_EncryptFinal_ex(&local_1ec,local_1f0 + local_1f8,&local_1f4);
                if (iVar7 != 0) {
                  iVar3 = ASN1_item_i2d((ASN1_VALUE *)val_00,pp,
                                        (ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
                }
              }
            }
          }
        }
        else {
          pEVar11 = EVP_md5();
          iVar3 = 0;
          iVar16 = EVP_Digest(local_120,local_1f8,(uchar *)local_120,(uint *)0x0,pEVar11,
                              (ENGINE *)0x0);
          if (iVar16 != 0) {
            local_110 = 0x4b434753;
            local_10c = 0x41535945;
            local_108 = 0x544c;
            local_1f8 = 0x1a;
            goto LAB_0814d853;
          }
        }
      }
    }
  }
  EVP_CIPHER_CTX_cleanup(&local_1ec);
  ASN1_item_free((ASN1_VALUE *)val_00,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)NETSCAPE_PKEY_it);
LAB_0814d70c:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

