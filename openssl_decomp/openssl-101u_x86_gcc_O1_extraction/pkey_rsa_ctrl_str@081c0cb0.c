
int pkey_rsa_ctrl_str(EVP_PKEY_CTX *param_1,byte *param_2,char *param_3)

{
  long lVar1;
  int iVar2;
  byte *pbVar3;
  char *pcVar4;
  byte *pbVar5;
  char *pcVar6;
  int in_GS_OFFSET;
  bool bVar7;
  bool bVar8;
  BIGNUM *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  bVar7 = false;
  bVar8 = param_3 == (char *)0x0;
  if (bVar8) {
    ERR_put_error(4,0x90,0x93,"rsa_pmeth.c",0x229);
    iVar2 = 0;
    goto LAB_081c0d58;
  }
  iVar2 = 0x11;
  pbVar3 = param_2;
  pbVar5 = (byte *)"rsa_padding_mode";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar7 = *pbVar3 < *pbVar5;
    bVar8 = *pbVar3 == *pbVar5;
    pbVar3 = pbVar3 + 1;
    pbVar5 = pbVar5 + 1;
  } while (bVar8);
  bVar7 = (!bVar7 && !bVar8) == bVar7;
  if (!bVar7) {
    iVar2 = 0x10;
    pbVar3 = param_2;
    pbVar5 = (byte *)"rsa_pss_saltlen";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar7 = *pbVar3 == *pbVar5;
      pbVar3 = pbVar3 + 1;
      pbVar5 = pbVar5 + 1;
    } while (bVar7);
    if (bVar7) {
      lVar1 = strtol(param_3,(char **)0x0,10);
      iVar2 = EVP_PKEY_CTX_ctrl(param_1,6,0x18,0x1002,lVar1,(void *)0x0);
    }
    else {
      iVar2 = 0x10;
      pbVar3 = param_2;
      pbVar5 = (byte *)"rsa_keygen_bits";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar7 = *pbVar3 == *pbVar5;
        pbVar3 = pbVar3 + 1;
        pbVar5 = pbVar5 + 1;
      } while (bVar7);
      if (bVar7) {
        lVar1 = strtol(param_3,(char **)0x0,10);
        iVar2 = EVP_PKEY_CTX_ctrl(param_1,6,4,0x1003,lVar1,(void *)0x0);
      }
      else {
        iVar2 = 0x12;
        pbVar3 = (byte *)"rsa_keygen_pubexp";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar7 = *param_2 == *pbVar3;
          param_2 = param_2 + 1;
          pbVar3 = pbVar3 + 1;
        } while (bVar7);
        if (bVar7) {
          local_24 = (BIGNUM *)0x0;
          iVar2 = BN_asc2bn(&local_24,param_3);
          if ((iVar2 != 0) && (iVar2 = EVP_PKEY_CTX_ctrl(param_1,6,4,0x1004,0,local_24), iVar2 < 1))
          {
            BN_free(local_24);
          }
        }
        else {
          iVar2 = -2;
        }
      }
    }
    goto LAB_081c0d58;
  }
  iVar2 = 6;
  pcVar4 = param_3;
  pcVar6 = "pkcs1";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar7 = *pcVar4 == *pcVar6;
    pcVar4 = pcVar4 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    iVar2 = 1;
  }
  else {
    iVar2 = 7;
    pcVar4 = param_3;
    pcVar6 = "sslv23";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar7 = *pcVar4 == *pcVar6;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (bVar7) {
      iVar2 = 2;
    }
    else {
      iVar2 = 5;
      pcVar4 = param_3;
      pcVar6 = "none";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar7 = *pcVar4 == *pcVar6;
        pcVar4 = pcVar4 + 1;
        pcVar6 = pcVar6 + 1;
      } while (bVar7);
      if (bVar7) {
        iVar2 = 3;
      }
      else {
        iVar2 = 5;
        pcVar4 = param_3;
        pcVar6 = "oeap";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar7 = *pcVar4 == *pcVar6;
          pcVar4 = pcVar4 + 1;
          pcVar6 = pcVar6 + 1;
        } while (bVar7);
        if (!bVar7) {
          iVar2 = 5;
          pcVar4 = param_3;
          pcVar6 = "oaep";
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar7 = *pcVar4 == *pcVar6;
            pcVar4 = pcVar4 + 1;
            pcVar6 = pcVar6 + 1;
          } while (bVar7);
          if (!bVar7) {
            iVar2 = 5;
            pcVar4 = param_3;
            pcVar6 = "x931";
            do {
              if (iVar2 == 0) break;
              iVar2 = iVar2 + -1;
              bVar7 = *pcVar4 == *pcVar6;
              pcVar4 = pcVar4 + 1;
              pcVar6 = pcVar6 + 1;
            } while (bVar7);
            if (bVar7) {
              iVar2 = 5;
            }
            else {
              if ((((*param_3 != 'p') || (param_3[1] != 's')) || (param_3[2] != 's')) ||
                 (param_3[3] != '\0')) {
                ERR_put_error(4,0x90,0x76,"rsa_pmeth.c",0x23d);
                iVar2 = -2;
                goto LAB_081c0d58;
              }
              iVar2 = 6;
            }
            goto LAB_081c0e25;
          }
        }
        iVar2 = 4;
      }
    }
  }
LAB_081c0e25:
  iVar2 = EVP_PKEY_CTX_ctrl(param_1,6,-1,0x1001,iVar2,(void *)0x0);
LAB_081c0d58:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}

