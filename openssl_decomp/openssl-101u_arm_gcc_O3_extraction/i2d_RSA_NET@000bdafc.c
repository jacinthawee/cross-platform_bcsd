
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int i2d_RSA_NET(RSA *a,uchar **pp,cb *cb,int sgckey)

{
  undefined4 *val;
  ASN1_STRING **val_00;
  ASN1_OBJECT *pAVar1;
  RSA *pRVar2;
  size_t sVar3;
  EVP_CIPHER *pEVar4;
  EVP_MD *pEVar5;
  ASN1_STRING *pAVar6;
  ASN1_OBJECT **ppAVar7;
  int iVar8;
  int iVar9;
  size_t local_204;
  int iStack_200;
  RSA *local_1fc;
  uchar auStack_1f8 [64];
  EVP_CIPHER_CTX EStack_1b8;
  uchar auStack_12c [16];
  undefined4 local_11c;
  undefined4 uStack_118;
  undefined2 local_114;
  int local_2c;
  
  local_2c = __stack_chk_guard;
  EVP_CIPHER_CTX_init(&EStack_1b8);
  pRVar2 = a;
  if (a == (RSA *)0x0) goto LAB_000bdc72;
  val = (undefined4 *)ASN1_item_new((ASN1_ITEM *)&NETSCAPE_PKEY_it);
  if ((val == (undefined4 *)0x0) ||
     (val_00 = (ASN1_STRING **)ASN1_item_new((ASN1_ITEM *)PTR_NETSCAPE_ENCRYPTED_PKEY_it_000bde00),
     val_00 == (ASN1_STRING **)0x0)) {
    val_00 = (ASN1_STRING **)0x0;
    pRVar2 = (RSA *)0x0;
  }
  else {
    ppAVar7 = (ASN1_OBJECT **)val[1];
    *val = 0;
    pAVar1 = OBJ_nid2obj(6);
    iVar9 = val[1];
    *ppAVar7 = pAVar1;
    pRVar2 = (RSA *)ASN1_TYPE_new();
    *(RSA **)(iVar9 + 4) = pRVar2;
    if (pRVar2 != (RSA *)0x0) {
      **(undefined4 **)(val[1] + 4) = 5;
      sVar3 = i2d_RSAPrivateKey(a,(uchar **)0x0);
      *(size_t *)val[2] = sVar3;
      iVar9 = ASN1_item_i2d((ASN1_VALUE *)val,(uchar **)0x0,(ASN1_ITEM *)&NETSCAPE_PKEY_it);
      pAVar6 = *val_00;
      ppAVar7 = (ASN1_OBJECT **)val_00[1]->length;
      *(int *)val_00[1]->type = iVar9;
      pAVar6->length = 0xb;
      pAVar1 = OBJ_nid2obj(5);
      iVar8 = val_00[1]->length;
      *ppAVar7 = pAVar1;
      pRVar2 = (RSA *)ASN1_TYPE_new();
      *(RSA **)(iVar8 + 4) = pRVar2;
      if (pRVar2 != (RSA *)0x0) {
        **(undefined4 **)(val_00[1]->length + 4) = 5;
        if (pp == (uchar **)0x0) {
          pRVar2 = (RSA *)ASN1_item_i2d((ASN1_VALUE *)val_00,(uchar **)0x0,
                                        (ASN1_ITEM *)PTR_NETSCAPE_ENCRYPTED_PKEY_it_000bde00);
          ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)&NETSCAPE_PKEY_it);
          ASN1_item_free((ASN1_VALUE *)val_00,(ASN1_ITEM *)PTR_NETSCAPE_ENCRYPTED_PKEY_it_000bde00);
          goto LAB_000bdc72;
        }
        pRVar2 = (RSA *)CRYPTO_malloc(sVar3,"n_pkey.c",0xab);
        local_1fc = pRVar2;
        if (pRVar2 == (RSA *)0x0) {
          ERR_put_error(0xd,0xa2,0x41,"n_pkey.c",0xac);
        }
        else {
          *(RSA **)(val[2] + 8) = pRVar2;
          i2d_RSAPrivateKey(a,(uchar **)&local_1fc);
          pRVar2 = (RSA *)CRYPTO_malloc(iVar9,"n_pkey.c",0xb4);
          iVar8 = 0xb5;
          local_1fc = pRVar2;
          if (pRVar2 != (RSA *)0x0) {
            pRVar2 = (RSA *)ASN1_STRING_set(*val_00,"private-key",-1);
            if (pRVar2 != (RSA *)0x0) {
              *(RSA **)(val_00[1]->type + 8) = local_1fc;
              ASN1_item_i2d((ASN1_VALUE *)val,(uchar **)&local_1fc,(ASN1_ITEM *)&NETSCAPE_PKEY_it);
              OPENSSL_cleanse(*(void **)(val[2] + 8),sVar3);
              if (cb == (cb *)0x0) {
                cb = EVP_read_pw_string + 1;
              }
              local_204 = (*cb)((char *)auStack_12c,0x100,"Enter Private Key password:",1);
              if (local_204 == 0) {
                sVar3 = strlen((char *)auStack_12c);
                local_204 = sVar3;
                if (sgckey != 0) {
                  pEVar5 = EVP_md5();
                  pRVar2 = (RSA *)EVP_Digest(auStack_12c,sVar3,auStack_12c,(uint *)0x0,pEVar5,
                                             (ENGINE *)0x0);
                  if (pRVar2 == (RSA *)0x0) goto LAB_000bdc56;
                  local_11c = s_SGCKEYSALT_0016243c._0_4_;
                  uStack_118 = s_SGCKEYSALT_0016243c._4_4_;
                  local_204 = 0x1a;
                  local_114 = (undefined2)ram0x00162444;
                }
                pEVar4 = EVP_rc4();
                pEVar5 = EVP_md5();
                pRVar2 = (RSA *)EVP_BytesToKey(pEVar4,pEVar5,(uchar *)0x0,auStack_12c,local_204,1,
                                               auStack_1f8,(uchar *)0x0);
                if (pRVar2 != (RSA *)0x0) {
                  OPENSSL_cleanse(auStack_12c,0x100);
                  local_1fc = *(RSA **)(val_00[1]->type + 8);
                  pEVar4 = EVP_rc4();
                  pRVar2 = (RSA *)EVP_EncryptInit_ex(&EStack_1b8,pEVar4,(ENGINE *)0x0,auStack_1f8,
                                                     (uchar *)0x0);
                  if (((pRVar2 != (RSA *)0x0) &&
                      (pRVar2 = (RSA *)EVP_EncryptUpdate(&EStack_1b8,(uchar *)local_1fc,
                                                         (int *)&local_204,(uchar *)local_1fc,iVar9)
                      , pRVar2 != (RSA *)0x0)) &&
                     (pRVar2 = (RSA *)EVP_EncryptFinal_ex(&EStack_1b8,
                                                          (uchar *)((int)&local_1fc->pad + local_204
                                                                   ),&iStack_200),
                     pRVar2 != (RSA *)0x0)) {
                    pRVar2 = (RSA *)ASN1_item_i2d((ASN1_VALUE *)val_00,pp,
                                                  (ASN1_ITEM *)
                                                  PTR_NETSCAPE_ENCRYPTED_PKEY_it_000bde00);
                  }
                }
              }
              else {
                pRVar2 = (RSA *)0x0;
                ERR_put_error(0xd,0xa2,0x67,"n_pkey.c",199);
              }
              goto LAB_000bdc56;
            }
            iVar8 = 0xba;
          }
          ERR_put_error(0xd,0xa2,0x41,"n_pkey.c",iVar8);
        }
      }
    }
  }
LAB_000bdc56:
  EVP_CIPHER_CTX_cleanup(&EStack_1b8);
  ASN1_item_free((ASN1_VALUE *)val_00,(ASN1_ITEM *)PTR_NETSCAPE_ENCRYPTED_PKEY_it_000bde00);
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)&NETSCAPE_PKEY_it);
LAB_000bdc72:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (int)pRVar2;
}

