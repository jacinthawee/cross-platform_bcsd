
undefined4
ssl_cipher_get_evp(int *param_1,int *param_2,int **param_3,int *param_4,undefined4 *param_5,
                  undefined4 *param_6)

{
  undefined *puVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int **ppiVar7;
  int iVar8;
  int local_38 [3];
  uint local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar8 = param_1[0x2d];
  local_2c = *(uint *)PTR___stack_chk_guard_006aabf0;
  uVar2 = 0;
  piVar6 = param_2;
  ppiVar7 = param_3;
  if (iVar8 == 0) goto LAB_004b4124;
  if (param_6 != (undefined4 *)0x0) {
    load_builtin_compressions();
    iVar5 = ssl_comp_methods;
    local_38[0] = param_1[0x2c];
    *param_6 = 0;
    if (iVar5 != 0) {
      piVar6 = local_38;
      piVar3 = (int *)(*(code *)PTR_sk_find_006a906c)();
      if ((int)piVar3 < 0) {
        *param_6 = 0;
      }
      else {
        uVar2 = (*(code *)PTR_sk_value_006a7f24)(ssl_comp_methods);
        *param_6 = uVar2;
        piVar6 = piVar3;
      }
    }
  }
  uVar2 = 0;
  if ((param_2 == (int *)0x0) || (param_3 == (int **)0x0)) goto LAB_004b4124;
  uVar4 = *(uint *)(iVar8 + 0x14);
  if (uVar4 == 0x40) {
    iVar5 = 6;
LAB_004b41d8:
    *param_2 = *(int *)(ssl_cipher_methods + iVar5 * 4);
  }
  else {
    if (0x40 < uVar4) {
      if (uVar4 == 0x400) {
        iVar5 = 10;
      }
      else if (uVar4 < 0x401) {
        if (uVar4 == 0x100) {
          iVar5 = 8;
        }
        else if (uVar4 == 0x200) {
          iVar5 = 9;
        }
        else {
          iVar5 = 7;
          if (uVar4 != 0x80) goto LAB_004b403c;
        }
      }
      else if (uVar4 == 0x1000) {
        iVar5 = 0xc;
      }
      else if (uVar4 == 0x2000) {
        iVar5 = 0xd;
      }
      else {
        iVar5 = 0xb;
        if (uVar4 != 0x800) goto LAB_004b403c;
      }
      goto LAB_004b41d8;
    }
    if (uVar4 == 4) {
      iVar5 = 2;
      goto LAB_004b41d8;
    }
    if (uVar4 < 5) {
      if (uVar4 == 1) {
        iVar5 = 0;
      }
      else {
        iVar5 = 1;
        if (uVar4 != 2) {
LAB_004b403c:
          *param_2 = 0;
          goto LAB_004b4040;
        }
      }
      goto LAB_004b41d8;
    }
    if (uVar4 == 0x10) {
      iVar5 = 4;
      goto LAB_004b41d8;
    }
    if (uVar4 != 0x20) {
      iVar5 = 3;
      if (uVar4 != 8) goto LAB_004b403c;
      goto LAB_004b41d8;
    }
    iVar5 = (*(code *)PTR_EVP_enc_null_006a94dc)();
    *param_2 = iVar5;
  }
LAB_004b4040:
  iVar5 = *(int *)(iVar8 + 0x18);
  if ((iVar5 - 1U < 0x20) && ((uint)(int)(char)(&DAT_0064886f)[iVar5] < 7)) {
    iVar5 = (char)(&DAT_0064886f)[iVar5] * 4;
    piVar6 = *(int **)(ssl_digest_methods + iVar5);
    *param_3 = piVar6;
    if (param_4 != (int *)0x0) {
      *param_4 = *(int *)(ssl_mac_pkey_id + iVar5);
    }
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = *(undefined4 *)(ssl_mac_secret_size + iVar5);
    }
    uVar2 = 0;
    if (*param_2 == 0) goto LAB_004b4124;
    if (piVar6 == (int *)0x0) goto LAB_004b425c;
  }
  else {
    *param_3 = (int *)0x0;
    if (param_4 != (int *)0x0) {
      *param_4 = 0;
    }
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = 0;
    }
    if (iVar5 == 0x40) {
      param_4 = (int *)0x0;
    }
    if (*param_2 == 0) {
      uVar2 = 0;
      goto LAB_004b4124;
    }
LAB_004b425c:
    iVar5 = (*(code *)PTR_EVP_CIPHER_flags_006a9270)();
    if (-1 < iVar5 << 10) {
      uVar2 = 0;
      goto LAB_004b4124;
    }
  }
  if ((param_4 != (int *)0x0) && (uVar2 = 0, *param_4 == 0)) goto LAB_004b4124;
  if ((*param_1 >> 8 == 3) && (*param_1 != 0x300)) {
    iVar5 = *(int *)(iVar8 + 0x14);
    if (iVar5 == 4) {
      uVar2 = 1;
      if (*(int *)(iVar8 + 0x18) != 1) goto LAB_004b4124;
      iVar5 = (*(code *)PTR_EVP_get_cipherbyname_006a8494)("RC4-HMAC-MD5");
      if (iVar5 == 0) {
        iVar5 = *(int *)(iVar8 + 0x14);
        goto LAB_004b4204;
      }
LAB_004b42a0:
      *param_2 = iVar5;
      uVar2 = 1;
      *param_3 = (int *)0x0;
      goto LAB_004b4124;
    }
LAB_004b4204:
    if (iVar5 == 0x40) {
      uVar2 = 1;
      if (*(int *)(iVar8 + 0x18) != 2) goto LAB_004b4124;
      iVar5 = (*(code *)PTR_EVP_get_cipherbyname_006a8494)("AES-128-CBC-HMAC-SHA1");
      if (iVar5 != 0) goto LAB_004b42a0;
      iVar5 = *(int *)(iVar8 + 0x14);
    }
    uVar2 = 1;
    if ((iVar5 != 0x80) || (uVar2 = 1, *(int *)(iVar8 + 0x18) != 2)) goto LAB_004b4124;
    iVar8 = (*(code *)PTR_EVP_get_cipherbyname_006a8494)("AES-256-CBC-HMAC-SHA1");
    if (iVar8 != 0) {
      *param_2 = iVar8;
      uVar2 = 1;
      *param_3 = (int *)0x0;
      goto LAB_004b4124;
    }
  }
  uVar2 = 1;
LAB_004b4124:
  if (local_2c == *(uint *)puVar1) {
    return uVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (5 < local_2c) {
    return 0;
  }
  iVar8 = *(int *)(ssl_handshake_digest_flag + local_2c * 4);
  *piVar6 = iVar8;
  if (iVar8 != 0) {
    *ppiVar7 = *(int **)(ssl_digest_methods + local_2c * 4);
    return 1;
  }
  *ppiVar7 = (int *)0x0;
  return 1;
}

