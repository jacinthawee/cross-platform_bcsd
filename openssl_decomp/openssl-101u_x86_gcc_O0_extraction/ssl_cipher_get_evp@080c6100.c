
undefined4
ssl_cipher_get_evp(int *param_1,EVP_CIPHER **param_2,int *param_3,int *param_4,undefined4 *param_5,
                  void **param_6)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  ulong uVar4;
  undefined4 uVar5;
  EVP_CIPHER *pEVar6;
  uint uVar7;
  int in_GS_OFFSET;
  int local_2c [3];
  int local_20;
  
  iVar1 = param_1[0x2d];
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (iVar1 != 0) {
    if (param_6 != (void **)0x0) {
      load_builtin_compressions();
      *param_6 = (void *)0x0;
      local_2c[0] = param_1[0x2c];
      if (ssl_comp_methods != (_STACK *)0x0) {
        iVar2 = sk_find(ssl_comp_methods,local_2c);
        if (iVar2 < 0) {
          *param_6 = (void *)0x0;
        }
        else {
          pvVar3 = sk_value(ssl_comp_methods,iVar2);
          *param_6 = pvVar3;
        }
      }
    }
    if ((param_2 != (EVP_CIPHER **)0x0) && (param_3 != (int *)0x0)) {
      uVar7 = *(uint *)(iVar1 + 0x14);
      if (uVar7 == 0x40) {
        iVar2 = 6;
LAB_080c6300:
        *param_2 = *(EVP_CIPHER **)(ssl_cipher_methods + iVar2 * 4);
      }
      else {
        if (0x40 < uVar7) {
          if (uVar7 == 0x400) {
            iVar2 = 10;
          }
          else if (uVar7 < 0x401) {
            if (uVar7 == 0x100) {
              iVar2 = 8;
            }
            else if (uVar7 == 0x200) {
              iVar2 = 9;
            }
            else {
              if (uVar7 != 0x80) goto LAB_080c62a6;
              iVar2 = 7;
            }
          }
          else if (uVar7 == 0x1000) {
            iVar2 = 0xc;
          }
          else if (uVar7 == 0x2000) {
            iVar2 = 0xd;
          }
          else {
            if (uVar7 != 0x800) goto LAB_080c62a6;
            iVar2 = 0xb;
          }
          goto LAB_080c6300;
        }
        if (uVar7 == 4) {
          iVar2 = 2;
          goto LAB_080c6300;
        }
        if (uVar7 < 5) {
          if (uVar7 == 1) {
            iVar2 = 0;
          }
          else {
            iVar2 = 1;
            if (uVar7 != 2) {
LAB_080c62a6:
              *param_2 = (EVP_CIPHER *)0x0;
              goto LAB_080c6309;
            }
          }
          goto LAB_080c6300;
        }
        if (uVar7 == 0x10) {
          iVar2 = 4;
          goto LAB_080c6300;
        }
        if (uVar7 != 0x20) {
          if (uVar7 != 8) goto LAB_080c62a6;
          iVar2 = 3;
          goto LAB_080c6300;
        }
        pEVar6 = EVP_enc_null();
        *param_2 = pEVar6;
      }
LAB_080c6309:
      iVar2 = *(int *)(iVar1 + 0x18);
      if ((iVar2 - 1U < 0x20) && (uVar7 = (uint)(char)(&DAT_0820097f)[iVar2], uVar7 < 6)) {
        iVar2 = *(int *)(ssl_digest_methods + uVar7 * 4);
        *param_3 = iVar2;
        if (param_4 != (int *)0x0) {
          *param_4 = *(int *)(ssl_mac_pkey_id + uVar7 * 4);
        }
        if (param_5 != (undefined4 *)0x0) {
          *param_5 = *(undefined4 *)(ssl_mac_secret_size + uVar7 * 4);
        }
        pEVar6 = *param_2;
        if (pEVar6 != (EVP_CIPHER *)0x0) {
          if (iVar2 == 0) goto LAB_080c623b;
LAB_080c6367:
          if ((param_4 == (int *)0x0) || (*param_4 != 0)) {
            if ((*param_1 >> 8 == 3) && (*param_1 != 0x300)) {
              iVar2 = *(int *)(iVar1 + 0x14);
              if (iVar2 == 4) {
                if (*(int *)(iVar1 + 0x18) == 1) {
                  pEVar6 = EVP_get_cipherbyname("RC4-HMAC-MD5");
                  if (pEVar6 == (EVP_CIPHER *)0x0) {
                    iVar2 = *(int *)(iVar1 + 0x14);
                    goto LAB_080c6394;
                  }
                  goto LAB_080c648e;
                }
              }
              else {
LAB_080c6394:
                if (iVar2 == 0x40) {
                  if (*(int *)(iVar1 + 0x18) != 2) goto LAB_080c63b0;
                  pEVar6 = EVP_get_cipherbyname("AES-128-CBC-HMAC-SHA1");
                  if (pEVar6 != (EVP_CIPHER *)0x0) goto LAB_080c648e;
                  iVar2 = *(int *)(iVar1 + 0x14);
                }
                if (((iVar2 == 0x80) && (*(int *)(iVar1 + 0x18) == 2)) &&
                   (pEVar6 = EVP_get_cipherbyname("AES-256-CBC-HMAC-SHA1"),
                   pEVar6 != (EVP_CIPHER *)0x0)) {
LAB_080c648e:
                  *param_2 = pEVar6;
                  *param_3 = 0;
                }
              }
            }
LAB_080c63b0:
            uVar5 = 1;
            goto LAB_080c6262;
          }
        }
      }
      else {
        *param_3 = 0;
        if (param_4 != (int *)0x0) {
          *param_4 = 0;
        }
        if (param_5 != (undefined4 *)0x0) {
          *param_5 = 0;
        }
        pEVar6 = *param_2;
        if (iVar2 == 0x40) {
          param_4 = (int *)0x0;
        }
        if (pEVar6 != (EVP_CIPHER *)0x0) {
LAB_080c623b:
          uVar4 = EVP_CIPHER_flags(pEVar6);
          if ((uVar4 & 0x200000) != 0) goto LAB_080c6367;
        }
      }
    }
  }
  uVar5 = 0;
LAB_080c6262:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}

