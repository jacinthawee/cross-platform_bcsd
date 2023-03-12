
uint ssl3_ctrl(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_2 == 2) {
    iVar3 = (*(code *)PTR_ssl_cert_inst_006a91f4)(param_1 + 0x98);
    if (iVar3 != 0) {
switchD_00489804_caseD_2:
      if (param_4 == (undefined4 *)0x0) {
        uVar5 = 0x43;
        uVar4 = 0xc4b;
      }
      else {
        iVar3 = (*(code *)PTR_RSAPrivateKey_dup_006a91f8)(param_4);
        if (iVar3 != 0) {
          iVar2 = *(int *)(param_1 + 0x98);
          if (*(int *)(iVar2 + 0x18) != 0) {
            (*(code *)PTR_RSA_free_006a86f0)();
            iVar2 = *(int *)(param_1 + 0x98);
          }
          *(int *)(iVar2 + 0x18) = iVar3;
          return 1;
        }
        uVar5 = 4;
        uVar4 = 0xc50;
      }
      goto LAB_00489834;
    }
LAB_00489820:
    uVar5 = 0x41;
    uVar4 = 0xc25;
    goto LAB_00489834;
  }
  if (param_2 == 5) {
    iVar3 = (*(code *)PTR_ssl_cert_inst_006a91f4)(param_1 + 0x98);
    if (iVar3 != 0) {
switchD_00489804_caseD_5:
      uVar5 = 0x42;
      uVar4 = 0xc5b;
      goto LAB_00489834;
    }
    goto LAB_00489820;
  }
  if (param_2 == 3) {
    iVar3 = (*(code *)PTR_ssl_cert_inst_006a91f4)(param_1 + 0x98);
    if (iVar3 == 0) goto LAB_00489820;
switchD_00489804_caseD_3:
    if (param_4 == (undefined4 *)0x0) {
      uVar5 = 0x43;
      uVar4 = 0xc66;
    }
    else {
      iVar3 = (*(code *)PTR_DHparams_dup_006a90f8)(param_4);
      if (iVar3 == 0) {
        uVar5 = 5;
        uVar4 = 0xc6b;
      }
      else {
        if ((*(int *)(param_1 + 0x100) << 0xb < 0) ||
           (iVar2 = (*(code *)PTR_DH_generate_key_006a90fc)(iVar3), iVar2 != 0)) {
          iVar2 = *(int *)(param_1 + 0x98);
          if (*(int *)(iVar2 + 0x20) != 0) {
            (*(code *)PTR_DH_free_006a8604)();
            iVar2 = *(int *)(param_1 + 0x98);
          }
          *(int *)(iVar2 + 0x20) = iVar3;
          return 1;
        }
        (*(code *)PTR_DH_free_006a8604)(iVar3);
        uVar5 = 5;
        uVar4 = 0xc73;
      }
    }
    goto LAB_00489834;
  }
  switch(param_2) {
  case 0:
  case 6:
  case 9:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x38:
  case 0x3a:
  case 0x3b:
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
  case 0x40:
  case 0x48:
  case 0x49:
  case 0x4a:
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x53:
  case 0x54:
    goto switchD_00489804_caseD_0;
  case 1:
    iVar3 = *(int *)(param_1 + 0x98);
    if ((iVar3 != 0) && (*(int *)(iVar3 + 0x18) == 0)) {
      if (*(int *)(iVar3 + 0x34) == 0) {
        return 1;
      }
      iVar3 = (*(code *)PTR_EVP_PKEY_size_006a85f4)();
      return iVar3 < 0x41 ^ 1;
    }
    goto switchD_00489804_caseD_0;
  case 2:
    goto switchD_00489804_caseD_2;
  case 3:
    goto switchD_00489804_caseD_3;
  case 4:
    if (param_4 == (undefined4 *)0x0) {
      uVar5 = 0x43;
      uVar4 = 0xc8b;
    }
    else {
      iVar3 = (*(code *)PTR_EC_KEY_up_ref_006a91fc)(param_4);
      if (iVar3 == 0) {
        uVar5 = 0x2b;
        uVar4 = 0xc90;
      }
      else {
        if ((*(int *)(param_1 + 0x100) << 0xc < 0) ||
           (iVar3 = (*(code *)PTR_EC_KEY_generate_key_006a82d4)(param_4), iVar3 != 0)) {
          iVar3 = *(int *)(param_1 + 0x98);
          if (*(int *)(iVar3 + 0x28) != 0) {
            (*(code *)PTR_EC_KEY_free_006a82d8)();
            iVar3 = *(int *)(param_1 + 0x98);
          }
          *(undefined4 **)(iVar3 + 0x28) = param_4;
          return 1;
        }
        (*(code *)PTR_EC_KEY_free_006a82d8)(param_4);
        uVar5 = 0x2b;
        uVar4 = 0xc99;
      }
    }
    goto LAB_00489834;
  case 5:
    goto switchD_00489804_caseD_5;
  case 7:
    uVar5 = 0x42;
    uVar4 = 0xca5;
    goto LAB_00489834;
  case 8:
    uVar1 = *(uint *)(param_1 + 0x6c);
    break;
  case 10:
    uVar1 = *(uint *)(*(int *)(param_1 + 0x58) + 0x19c);
    break;
  case 0xb:
    uVar1 = *(uint *)(*(int *)(param_1 + 0x58) + 0x19c);
    *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x19c) = 0;
    break;
  case 0xc:
    uVar1 = *(uint *)(*(int *)(param_1 + 0x58) + 0x198);
    break;
  case 0xd:
    uVar1 = **(uint **)(param_1 + 0x58);
    break;
  case 0x37:
    if (param_3 == 0) {
      if (*(int *)(param_1 + 0x120) != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
      }
      *(undefined4 *)(param_1 + 0x120) = 0;
      if (param_4 == (undefined4 *)0x0) {
        return 1;
      }
      uVar1 = (*(code *)PTR_strlen_006aab30)(param_4);
      if (uVar1 < 0x100) {
        iVar3 = (*(code *)PTR_BUF_strdup_006a80dc)(param_4);
        *(int *)(param_1 + 0x120) = iVar3;
        if (iVar3 != 0) {
          return 1;
        }
        uVar5 = 0x44;
        uVar4 = 0xcbc;
      }
      else {
        uVar5 = 0x13f;
        uVar4 = 0xcb7;
      }
    }
    else {
      uVar5 = 0x140;
      uVar4 = 0xcc2;
    }
    goto LAB_00489834;
  case 0x39:
    *(undefined4 **)(param_1 + 0x11c) = param_4;
    uVar1 = 1;
    break;
  case 0x41:
    *(int *)(param_1 + 0x128) = param_3;
    uVar1 = 1;
    break;
  case 0x42:
    uVar1 = 1;
    *param_4 = *(undefined4 *)(param_1 + 0x134);
    break;
  case 0x43:
    *(undefined4 **)(param_1 + 0x134) = param_4;
    uVar1 = 1;
    break;
  case 0x44:
    uVar1 = 1;
    *param_4 = *(undefined4 *)(param_1 + 0x130);
    break;
  case 0x45:
    *(undefined4 **)(param_1 + 0x130) = param_4;
    uVar1 = 1;
    break;
  case 0x46:
    uVar1 = *(uint *)(param_1 + 0x13c);
    *param_4 = *(undefined4 *)(param_1 + 0x138);
    break;
  case 0x47:
    if (*(int *)(param_1 + 0x138) != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    *(undefined4 **)(param_1 + 0x138) = param_4;
    uVar1 = 1;
    *(int *)(param_1 + 0x13c) = param_3;
    break;
  case 0x55:
    iVar3 = (*(code *)PTR_SSL_version_006a88d8)();
    UNRECOVERED_JUMPTABLE = (code *)PTR_dtls1_heartbeat_006a9204;
    if ((iVar3 != 0xfeff) &&
       (iVar3 = (*(code *)PTR_SSL_version_006a88d8)(param_1),
       UNRECOVERED_JUMPTABLE = (code *)PTR_dtls1_heartbeat_006a9204, iVar3 != 0x100)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR_tls1_heartbeat_006a9200;
    }
                    /* WARNING: Could not recover jumptable at 0x00489afc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(param_1);
    return uVar1;
  case 0x56:
    uVar1 = *(uint *)(param_1 + 0x188);
    break;
  case 0x57:
    uVar1 = 1;
    if (param_3 == 0) {
      *(uint *)(param_1 + 0x184) = *(uint *)(param_1 + 0x184) & 0xfffffffb;
    }
    else {
      *(uint *)(param_1 + 0x184) = *(uint *)(param_1 + 0x184) | 4;
    }
    break;
  default:
    iVar3 = (*(code *)PTR_ssl_cert_inst_006a91f4)(param_1 + 0x98);
    if (iVar3 == 0) goto LAB_00489820;
    uVar5 = 0x42;
    uVar4 = 0xc7f;
LAB_00489834:
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xd5,uVar5,"s3_lib.c",uVar4);
switchD_00489804_caseD_0:
    uVar1 = 0;
  }
  return uVar1;
}

