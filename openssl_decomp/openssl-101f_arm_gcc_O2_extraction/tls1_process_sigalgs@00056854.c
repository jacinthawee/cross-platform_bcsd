
undefined4 tls1_process_sigalgs(int *param_1,undefined *param_2,int param_3)

{
  EVP_MD *pEVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  
  iVar3 = param_1[0x26];
  if (*param_1 >> 8 != 3) {
    return 1;
  }
  if (*param_1 < 0x303) {
    return 1;
  }
  if (iVar3 == 0) {
    return 0;
  }
  *(undefined4 *)(iVar3 + 0x50) = 0;
  *(undefined4 *)(iVar3 + 0x44) = 0;
  *(undefined4 *)(iVar3 + 0x38) = 0;
  *(undefined4 *)(iVar3 + 0x74) = 0;
  if (0 < param_3) {
    puVar4 = param_2 + (param_3 - 1U & 0xfffffffe) + 2;
    do {
      uVar2 = (uint)(byte)param_2[1];
      if (uVar2 == 2) {
LAB_000568ac:
        if (*(int *)(iVar3 + uVar2 * 0xc + 0x38) == 0) {
          switch(*param_2) {
          case 2:
            pEVar1 = EVP_sha1();
            break;
          case 3:
            pEVar1 = EVP_sha224();
            break;
          case 4:
            pEVar1 = EVP_sha256();
            break;
          case 5:
            pEVar1 = EVP_sha384();
            break;
          case 6:
            pEVar1 = EVP_sha512();
            break;
          default:
            goto switchD_000568c4_caseD_5;
          }
          if (pEVar1 != (EVP_MD *)0x0) {
            *(EVP_MD **)(iVar3 + uVar2 * 0xc + 0x38) = pEVar1;
            if (uVar2 == 1) {
              *(EVP_MD **)(iVar3 + 0x38) = pEVar1;
            }
          }
        }
      }
      else {
        if (uVar2 == 3) {
          uVar2 = 5;
          goto LAB_000568ac;
        }
        if (uVar2 == 1) goto LAB_000568ac;
      }
switchD_000568c4_caseD_5:
      param_2 = param_2 + 2;
    } while (param_2 != puVar4);
    if (*(int *)(iVar3 + 0x50) != 0) goto LAB_000568d8;
  }
  pEVar1 = EVP_sha1();
  *(EVP_MD **)(iVar3 + 0x50) = pEVar1;
LAB_000568d8:
  if (*(int *)(iVar3 + 0x44) == 0) {
    pEVar1 = EVP_sha1();
    *(EVP_MD **)(iVar3 + 0x44) = pEVar1;
    pEVar1 = EVP_sha1();
    *(EVP_MD **)(iVar3 + 0x38) = pEVar1;
  }
  if (*(int *)(iVar3 + 0x74) != 0) {
    return 1;
  }
  pEVar1 = EVP_sha1();
  *(EVP_MD **)(iVar3 + 0x74) = pEVar1;
  return 1;
}

