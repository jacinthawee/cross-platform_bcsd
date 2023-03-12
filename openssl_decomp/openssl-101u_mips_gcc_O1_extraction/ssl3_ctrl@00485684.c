
uint ssl3_ctrl(int *param_1,int param_2,int param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  SSL_METHOD *pSVar4;
  int iVar5;
  undefined4 uVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_2 == 2) {
    iVar2 = (*(code *)PTR_ssl_cert_inst_006a80b8)(param_1 + 0x26);
    if (iVar2 != 0) {
switchD_004856e0_caseD_2:
      if (param_4 == (int *)0x0) {
        uVar6 = 0x43;
        uVar3 = 0xc75;
      }
      else {
        iVar2 = (*(code *)PTR_RSAPrivateKey_dup_006a80bc)(param_4);
        if (iVar2 != 0) {
          iVar5 = param_1[0x26];
          if (*(int *)(iVar5 + 0x18) != 0) {
            (*(code *)PTR_RSA_free_006a7600)();
            iVar5 = param_1[0x26];
          }
          *(int *)(iVar5 + 0x18) = iVar2;
          return 1;
        }
        uVar6 = 4;
        uVar3 = 0xc79;
      }
      goto LAB_00485710;
    }
LAB_004856fc:
    uVar6 = 0x41;
    uVar3 = 0xc50;
    goto LAB_00485710;
  }
  if (param_2 == 5) {
    iVar2 = (*(code *)PTR_ssl_cert_inst_006a80b8)(param_1 + 0x26);
    if (iVar2 != 0) {
switchD_004856e0_caseD_5:
      uVar6 = 0x42;
      uVar3 = 0xc84;
      goto LAB_00485710;
    }
    goto LAB_004856fc;
  }
  if (param_2 == 3) {
    iVar2 = (*(code *)PTR_ssl_cert_inst_006a80b8)(param_1 + 0x26);
    if (iVar2 == 0) goto LAB_004856fc;
switchD_004856e0_caseD_3:
    if (param_4 == (int *)0x0) {
      uVar6 = 0x43;
      uVar3 = 0xc8e;
    }
    else {
      iVar2 = (*(code *)PTR_DHparams_dup_006a7f8c)(param_4);
      if (iVar2 != 0) {
        iVar5 = param_1[0x26];
        if (*(int *)(iVar5 + 0x20) != 0) {
          (*(code *)PTR_DH_free_006a7508)();
          iVar5 = param_1[0x26];
        }
        *(int *)(iVar5 + 0x20) = iVar2;
        return 1;
      }
      uVar6 = 5;
      uVar3 = 0xc92;
    }
    goto LAB_00485710;
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
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5b:
  case 0x5c:
  case 0x5d:
  case 0x5e:
  case 0x5f:
  case 0x60:
  case 0x61:
  case 0x62:
  case 99:
  case 100:
  case 0x65:
  case 0x66:
  case 0x67:
  case 0x68:
  case 0x69:
  case 0x6a:
  case 0x6b:
  case 0x6c:
  case 0x6d:
  case 0x6e:
  case 0x6f:
  case 0x70:
  case 0x71:
  case 0x72:
  case 0x73:
  case 0x74:
  case 0x75:
  case 0x76:
    goto switchD_004856e0_caseD_0;
  case 1:
    iVar2 = param_1[0x26];
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x18) == 0)) {
      if (*(int *)(iVar2 + 0x34) == 0) {
        return 1;
      }
      iVar2 = (*(code *)PTR_EVP_PKEY_size_006a74f8)();
      return iVar2 < 0x41 ^ 1;
    }
    goto switchD_004856e0_caseD_0;
  case 2:
    goto switchD_004856e0_caseD_2;
  case 3:
    goto switchD_004856e0_caseD_3;
  case 4:
    if (param_4 == (int *)0x0) {
      uVar6 = 0x43;
      uVar3 = 0xca8;
    }
    else {
      iVar2 = (*(code *)PTR_EC_KEY_up_ref_006a80c4)(param_4);
      if (iVar2 == 0) {
        uVar6 = 0x2b;
        uVar3 = 0xcac;
      }
      else {
        if ((param_1[0x40] << 0xc < 0) ||
           (iVar2 = (*(code *)PTR_EC_KEY_generate_key_006a71d0)(param_4), iVar2 != 0)) {
          iVar2 = param_1[0x26];
          if (*(int *)(iVar2 + 0x28) != 0) {
            (*(code *)PTR_EC_KEY_free_006a71d4)();
            iVar2 = param_1[0x26];
          }
          *(int **)(iVar2 + 0x28) = param_4;
          return 1;
        }
        (*(code *)PTR_EC_KEY_free_006a71d4)(param_4);
        uVar6 = 0x2b;
        uVar3 = 0xcb3;
      }
    }
    goto LAB_00485710;
  case 5:
    goto switchD_004856e0_caseD_5;
  case 7:
    uVar6 = 0x42;
    uVar3 = 0xcbf;
    goto LAB_00485710;
  case 8:
    uVar1 = param_1[0x1b];
    break;
  case 10:
    uVar1 = *(uint *)(param_1[0x16] + 0x19c);
    break;
  case 0xb:
    uVar1 = *(uint *)(param_1[0x16] + 0x19c);
    *(undefined4 *)(param_1[0x16] + 0x19c) = 0;
    break;
  case 0xc:
    uVar1 = *(uint *)(param_1[0x16] + 0x198);
    break;
  case 0xd:
    uVar1 = *(uint *)param_1[0x16];
    break;
  case 0x37:
    if (param_3 == 0) {
      if (param_1[0x48] != 0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
      param_1[0x48] = 0;
      if (param_4 == (int *)0x0) {
        return 1;
      }
      iVar2 = (*(code *)PTR_strlen_006a9a24)(param_4);
      if (iVar2 - 1U < 0xff) {
        iVar2 = (*(code *)PTR_BUF_strdup_006a6fdc)(param_4);
        param_1[0x48] = iVar2;
        if (iVar2 != 0) {
          return 1;
        }
        uVar6 = 0x44;
        uVar3 = 0xcd6;
      }
      else {
        uVar6 = 0x13f;
        uVar3 = 0xcd2;
      }
    }
    else {
      uVar6 = 0x140;
      uVar3 = 0xcda;
    }
    goto LAB_00485710;
  case 0x39:
    param_1[0x47] = (int)param_4;
    uVar1 = 1;
    break;
  case 0x41:
    param_1[0x4a] = param_3;
    uVar1 = 1;
    break;
  case 0x42:
    uVar1 = 1;
    *param_4 = param_1[0x4d];
    break;
  case 0x43:
    param_1[0x4d] = (int)param_4;
    uVar1 = 1;
    break;
  case 0x44:
    uVar1 = 1;
    *param_4 = param_1[0x4c];
    break;
  case 0x45:
    param_1[0x4c] = (int)param_4;
    uVar1 = 1;
    break;
  case 0x46:
    uVar1 = param_1[0x4f];
    *param_4 = param_1[0x4e];
    break;
  case 0x47:
    if (param_1[0x4e] != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    param_1[0x4e] = (int)param_4;
    uVar1 = 1;
    param_1[0x4f] = param_3;
    break;
  case 0x55:
    iVar2 = (*(code *)PTR_SSL_version_006a77ec)();
    UNRECOVERED_JUMPTABLE = (code *)PTR_dtls1_heartbeat_006a80cc;
    if ((iVar2 != 0xfeff) &&
       (iVar2 = (*(code *)PTR_SSL_version_006a77ec)(param_1),
       UNRECOVERED_JUMPTABLE = (code *)PTR_dtls1_heartbeat_006a80cc, iVar2 != 0x100)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR_tls1_heartbeat_006a80c0;
    }
                    /* WARNING: Could not recover jumptable at 0x00485870. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(param_1);
    return uVar1;
  case 0x56:
    uVar1 = param_1[0x62];
    break;
  case 0x57:
    uVar1 = 1;
    if (param_3 == 0) {
      param_1[0x61] = param_1[0x61] & 0xfffffffb;
    }
    else {
      param_1[0x61] = param_1[0x61] | 4;
    }
    break;
  case 0x77:
    iVar2 = **(int **)param_1[0x39];
    if (*param_1 == iVar2) {
      return 1;
    }
    pSVar4 = SSLv23_method();
    if (iVar2 != pSVar4->version) {
      return 0;
    }
    iVar2 = param_1[0x40];
    if (-1 < iVar2 << 4) {
      return (uint)(*param_1 == 0x303);
    }
    if (-1 < iVar2 << 3) {
      return (uint)(*param_1 == 0x302);
    }
    if (-1 < iVar2 << 5) {
      return (uint)(*param_1 == 0x301);
    }
    if (-1 < iVar2 << 6) {
      return (uint)(*param_1 == 0x300);
    }
    if (-1 < iVar2 << 7) {
      return (uint)(*param_1 == 2);
    }
    goto switchD_004856e0_caseD_0;
  default:
    iVar2 = (*(code *)PTR_ssl_cert_inst_006a80b8)(param_1 + 0x26);
    if (iVar2 == 0) goto LAB_004856fc;
    uVar6 = 0x42;
    uVar3 = 0xc9d;
LAB_00485710:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xd5,uVar6,"s3_lib.c",uVar3);
switchD_004856e0_caseD_0:
    uVar1 = 0;
  }
  return uVar1;
}

