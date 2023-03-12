
undefined4 prime_main(int param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  char **ppcVar4;
  BIO_METHOD *pBVar5;
  BIO *bp;
  int iVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  char *pcVar9;
  char **ppcVar10;
  char *pcVar11;
  char *pcVar12;
  int in_GS_OFFSET;
  bool bVar13;
  byte bVar14;
  long local_38;
  long local_34;
  int local_30;
  BIGNUM *local_24;
  int local_20;
  
  bVar14 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = (BIGNUM *)0x0;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar5 = BIO_s_file();
    bio_err = BIO_new(pBVar5);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  ppcVar10 = (char **)(param_2 + 4);
  param_1 = param_1 + -1;
  if (param_1 < 1) {
    pcVar9 = *(char **)(param_2 + 4);
    bVar13 = true;
    local_30 = 0;
    local_38 = 0;
    bVar2 = false;
    local_34 = 0x14;
    bVar3 = false;
LAB_0809053d:
    if ((pcVar9 == (char *)0x0) && (bVar13)) {
      BIO_printf(bio_err,"No prime specified\n");
LAB_08090563:
      BIO_printf(bio_err,"options are\n");
      BIO_printf(bio_err,"%-14s hex\n",&DAT_081ec27e);
      BIO_printf(bio_err,"%-14s number of checks\n","-checks <n>");
      uVar8 = 1;
      goto LAB_080906dc;
    }
  }
  else {
    pcVar9 = *(char **)(param_2 + 4);
    local_30 = 0;
    local_38 = 0;
    bVar2 = false;
    local_34 = 0x14;
    bVar3 = false;
    cVar1 = *pcVar9;
    while (bVar13 = cVar1 == '-', bVar13) {
      iVar6 = 5;
      pcVar11 = pcVar9;
      pcVar12 = "-hex";
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        bVar13 = *pcVar11 == *pcVar12;
        pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
        pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
      } while (bVar13);
      ppcVar4 = ppcVar10;
      if (bVar13) {
        bVar3 = true;
      }
      else {
        iVar6 = 10;
        pcVar11 = pcVar9;
        pcVar12 = "-generate";
        do {
          if (iVar6 == 0) break;
          iVar6 = iVar6 + -1;
          bVar13 = *pcVar11 == *pcVar12;
          pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
          pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
        } while (bVar13);
        if (bVar13) {
          bVar2 = true;
        }
        else {
          iVar6 = 6;
          pcVar11 = pcVar9;
          pcVar12 = "-bits";
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar13 = *pcVar11 == *pcVar12;
            pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
            pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
          } while (bVar13);
          if (bVar13) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_08090563;
            local_38 = strtol(ppcVar10[1],(char **)0x0,10);
            ppcVar4 = ppcVar10 + 1;
          }
          else {
            iVar6 = 6;
            pcVar11 = pcVar9;
            pcVar12 = "-safe";
            do {
              if (iVar6 == 0) break;
              iVar6 = iVar6 + -1;
              bVar13 = *pcVar11 == *pcVar12;
              pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
              pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
            } while (bVar13);
            if (bVar13) {
              local_30 = 1;
            }
            else {
              iVar6 = 8;
              pcVar11 = pcVar9;
              pcVar12 = "-checks";
              do {
                if (iVar6 == 0) break;
                iVar6 = iVar6 + -1;
                bVar13 = *pcVar11 == *pcVar12;
                pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
                pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
              } while (bVar13);
              if (!bVar13) {
                BIO_printf(bio_err,"Unknown option \'%s\'\n",pcVar9);
                goto LAB_08090563;
              }
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_08090563;
              local_34 = strtol(ppcVar10[1],(char **)0x0,10);
              ppcVar4 = ppcVar10 + 1;
            }
          }
        }
      }
      param_1 = param_1 + -1;
      ppcVar10 = ppcVar4 + 1;
      if (param_1 == 0) {
        pcVar9 = ppcVar4[1];
        bVar13 = (bool)(bVar2 ^ 1);
        goto LAB_0809053d;
      }
      pcVar9 = ppcVar4[1];
      cVar1 = *pcVar9;
    }
  }
  pBVar5 = BIO_s_file();
  bp = BIO_new(pBVar5);
  if (bp != (BIO *)0x0) {
    BIO_ctrl(bp,0x6a,0,stdout);
  }
  if (bVar2) {
    if (local_38 == 0) {
      BIO_printf(bio_err,"Specifiy the number of bits.\n");
      uVar8 = 1;
      goto LAB_080906dc;
    }
    local_24 = BN_new();
    BN_generate_prime_ex(local_24,local_38,local_30,(BIGNUM *)0x0,(BIGNUM *)0x0,(BN_GENCB *)0x0);
    if (bVar3) {
      pcVar9 = BN_bn2hex(local_24);
    }
    else {
      pcVar9 = BN_bn2dec(local_24);
    }
    BIO_printf(bp,"%s\n",pcVar9);
    CRYPTO_free(pcVar9);
  }
  else {
    if (bVar3) {
      BN_hex2bn(&local_24,*ppcVar10);
    }
    else {
      BN_dec2bn(&local_24,*ppcVar10);
    }
    BN_print(bp,local_24);
    iVar6 = BN_is_prime_ex(local_24,local_34,(BN_CTX *)0x0,(BN_GENCB *)0x0);
    puVar7 = &UNK_081fce71;
    if (iVar6 != 0) {
      puVar7 = &DAT_081ec74a;
    }
    BIO_printf(bp," is %sprime\n",puVar7);
  }
  BN_free(local_24);
  BIO_free_all(bp);
  uVar8 = 0;
LAB_080906dc:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar8;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

