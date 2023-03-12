
undefined4 prime_main(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  BIO_METHOD *pBVar3;
  BIO *bp;
  char **ppcVar4;
  char **ppcVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  long bits;
  long local_34;
  BIGNUM *local_2c [2];
  
  local_2c[0] = (BIGNUM *)0x0;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar3 = BIO_s_file();
    bio_err = BIO_new(pBVar3);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  param_1 = param_1 + -1;
  ppcVar4 = (char **)(param_2 + 4);
  if (param_1 < 1) {
    if (*(int *)(param_2 + 4) == 0) {
LAB_00041e1a:
      BIO_printf(bio_err,"No prime specified\n");
LAB_00041e2a:
      BIO_printf(bio_err,"options are\n");
      BIO_printf(bio_err,"%-14s hex\n",&DAT_00125b5c);
      BIO_printf(bio_err,"%-14s number of checks\n","-checks <n>");
      return 1;
    }
  }
  else {
    pcVar7 = *(char **)(param_2 + 4);
    iVar8 = 0;
    if (*pcVar7 == '-') {
      bits = 0;
      local_34 = 0x14;
      iVar6 = 0;
      bVar1 = false;
      ppcVar5 = ppcVar4;
      do {
        iVar2 = strcmp(pcVar7,"-hex");
        if (iVar2 == 0) {
          param_1 = param_1 + -1;
          iVar6 = 1;
          ppcVar4 = ppcVar5 + 1;
          if (0 < param_1) goto LAB_00041cd2;
LAB_00041cfa:
          if (ppcVar5[1] == (char *)0x0) {
            if (!bVar1) goto LAB_00041e1a;
            bVar1 = true;
          }
          break;
        }
        iVar2 = strcmp(pcVar7,"-generate");
        if (iVar2 == 0) {
          bVar1 = true;
        }
        else {
          iVar2 = strcmp(pcVar7,"-bits");
          if (iVar2 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_00041e2a;
            bits = strtol(ppcVar5[1],(char **)0x0,10);
            ppcVar5 = ppcVar5 + 1;
          }
          else {
            iVar2 = strcmp(pcVar7,"-safe");
            if (iVar2 == 0) {
              iVar8 = 1;
            }
            else {
              iVar2 = strcmp(pcVar7,"-checks");
              if (iVar2 != 0) {
                BIO_printf(bio_err,"Unknown option \'%s\'\n",pcVar7);
                goto LAB_00041e2a;
              }
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_00041e2a;
              local_34 = strtol(ppcVar5[1],(char **)0x0,10);
              ppcVar5 = ppcVar5 + 1;
            }
          }
        }
        param_1 = param_1 + -1;
        ppcVar4 = ppcVar5 + 1;
        if (param_1 < 1) goto LAB_00041cfa;
LAB_00041cd2:
        pcVar7 = ppcVar5[1];
        ppcVar5 = ppcVar4;
      } while (*pcVar7 == '-');
      goto LAB_00041d0a;
    }
  }
  iVar6 = 0;
  bVar1 = false;
  local_34 = 0x14;
  iVar8 = iVar6;
  bits = iVar6;
LAB_00041d0a:
  pBVar3 = BIO_s_file();
  bp = BIO_new(pBVar3);
  if (bp != (BIO *)0x0) {
    BIO_ctrl(bp,0x6a,0,stdout);
  }
  if (bVar1) {
    if (bits == 0) {
      BIO_printf(bio_err,"Specifiy the number of bits.\n");
      return 1;
    }
    local_2c[0] = BN_new();
    BN_generate_prime_ex(local_2c[0],bits,iVar8,(BIGNUM *)0x0,(BIGNUM *)0x0,(BN_GENCB *)0x0);
    if (iVar6 == 0) {
      pcVar7 = BN_bn2dec(local_2c[0]);
    }
    else {
      pcVar7 = BN_bn2hex(local_2c[0]);
    }
    BIO_printf(bp,"%s\n",pcVar7);
    CRYPTO_free(pcVar7);
  }
  else {
    if (iVar6 == 0) {
      BN_dec2bn(local_2c,*ppcVar4);
    }
    else {
      BN_hex2bn(local_2c,*ppcVar4);
    }
    BN_print(bp,local_2c[0]);
    iVar8 = BN_is_prime_ex(local_2c[0],local_34,(BN_CTX *)0x0,(BN_GENCB *)0x0);
    pcVar7 = "not ";
    if (iVar8 != 0) {
      pcVar7 = "";
    }
    BIO_printf(bp," is %sprime\n",pcVar7);
  }
  BN_free(local_2c[0]);
  BIO_free_all(bp);
  return 0;
}

