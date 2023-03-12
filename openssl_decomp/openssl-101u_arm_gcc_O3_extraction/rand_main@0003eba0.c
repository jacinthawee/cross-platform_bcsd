
void rand_main(undefined4 param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  BIO_METHOD *pBVar5;
  BIO *pBVar6;
  int iVar7;
  ushort **ppuVar8;
  BIO *b;
  void *pvVar9;
  byte *pbVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  void *local_1044;
  int local_1040;
  int local_1038;
  int local_1030;
  byte local_102c [4096];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  local_1030 = -1;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar5 = BIO_s_file();
    bio_err = BIO_new(pBVar5);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar3 = load_config(bio_err,0);
  if (iVar3 != 0) {
    iVar12 = 0;
    iVar3 = 0;
    bVar1 = false;
    bVar2 = false;
    local_1038 = local_1030;
    local_1040 = 0;
    local_1044 = (void *)0x0;
LAB_0003ec04:
    do {
      pbVar10 = *(byte **)(param_2 + (iVar3 + 1) * 4);
      iVar4 = iVar3 + 1;
      iVar7 = iVar3;
      while( true ) {
        iVar3 = iVar4;
        if (pbVar10 == (byte *)0x0) goto LAB_0003ec3a;
        iVar13 = iVar3 * 4;
        iVar4 = strcmp((char *)pbVar10,"-out");
        if (iVar4 == 0) {
          pvVar9 = *(void **)(iVar13 + param_2 + 4);
          if ((pvVar9 == (void *)0x0) || (local_1044 != (void *)0x0)) goto LAB_0003ec38;
          iVar3 = iVar7 + 2;
          local_1044 = pvVar9;
          goto LAB_0003ec04;
        }
        iVar4 = strcmp((char *)pbVar10,"-engine");
        if (iVar4 != 0) break;
        iVar3 = *(int *)(iVar13 + param_2 + 4);
        if ((iVar3 == 0) || (iVar12 != 0)) goto LAB_0003ec38;
        pbVar10 = *(byte **)(param_2 + (iVar7 + 3) * 4);
        iVar4 = iVar7 + 3;
        iVar7 = iVar7 + 2;
        iVar12 = iVar3;
      }
      iVar4 = strcmp((char *)pbVar10,"-rand");
      if (iVar4 != 0) {
        iVar7 = strcmp((char *)pbVar10,"-base64");
        if (iVar7 == 0) {
          if (bVar2) goto LAB_0003ec38;
          bVar2 = true;
        }
        else {
          iVar7 = strcmp((char *)pbVar10,"-hex");
          if (iVar7 == 0) {
            if (bVar1) goto LAB_0003ec38;
            bVar1 = true;
          }
          else {
            ppuVar8 = __ctype_b_loc();
            if ((-1 < (int)((uint)(*ppuVar8)[*pbVar10] << 0x14)) || (-1 < local_1038))
            goto LAB_0003ec38;
            iVar7 = __isoc99_sscanf(pbVar10,"%d",&local_1030);
            local_1038 = local_1030;
            if ((iVar7 == 0) || (local_1030 < 0)) goto LAB_0003ec38;
          }
        }
        goto LAB_0003ec04;
      }
      iVar4 = *(int *)(iVar13 + param_2 + 4);
      if ((iVar4 == 0) || (local_1040 != 0)) goto LAB_0003ec38;
      iVar3 = iVar7 + 2;
      local_1040 = iVar4;
    } while( true );
  }
LAB_0003ecb6:
  uVar11 = 1;
  ERR_print_errors(bio_err);
LAB_0003ecc0:
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar11);
LAB_0003ec38:
  pbVar10 = (byte *)0x1;
LAB_0003ec3a:
  if ((((bool)(bVar2 & bVar1)) || (local_1038 < 0)) || (pbVar10 != (byte *)0x0)) {
    BIO_printf(bio_err,"Usage: rand [options] num\n");
    BIO_printf(bio_err,"where options are\n");
    BIO_printf(bio_err,"-out file             - write to file\n");
    BIO_printf(bio_err,"-engine e             - use engine e, possibly a hardware device.\n");
    BIO_printf(bio_err,"-rand file%cfile%c... - seed PRNG from files\n",0x3a,0x3a);
    BIO_printf(bio_err,"-base64               - base64 encode output\n");
    BIO_printf(bio_err,"-hex                  - hex encode output\n");
  }
  else {
    iVar3 = local_1040;
    if (local_1040 != 0) {
      iVar3 = 1;
    }
    setup_engine(bio_err,iVar12,0);
    app_RAND_load_file(0,bio_err,iVar3);
    pBVar6 = bio_err;
    if (iVar3 != 0) {
      uVar11 = app_RAND_load_files(local_1040);
      BIO_printf(pBVar6,"%ld semi-random bytes loaded\n",uVar11);
    }
    pBVar5 = BIO_s_file();
    pBVar6 = BIO_new(pBVar5);
    if (pBVar6 != (BIO *)0x0) {
      if (local_1044 == (void *)0x0) {
        iVar3 = BIO_ctrl(pBVar6,0x6a,0x10,stdout);
      }
      else {
        iVar3 = BIO_ctrl(pBVar6,0x6c,5,local_1044);
      }
      if (iVar3 < 1) {
LAB_0003ef16:
        uVar11 = 1;
        ERR_print_errors(bio_err);
      }
      else {
        if (bVar2) {
          pBVar5 = BIO_f_base64();
          b = BIO_new(pBVar5);
          if (b == (BIO *)0x0) goto LAB_0003ef16;
          pBVar6 = BIO_push(b,pBVar6);
        }
        if (0 < local_1030) {
          do {
            while( true ) {
              iVar3 = local_1030;
              if (0xfff < local_1030) {
                iVar3 = 0x1000;
              }
              iVar12 = RAND_bytes(local_102c,iVar3);
              if (iVar12 < 1) {
                uVar11 = 1;
                goto LAB_0003edc6;
              }
              iVar12 = 0;
              if (!bVar1) break;
              do {
                pbVar10 = local_102c + iVar12;
                iVar12 = iVar12 + 1;
                BIO_printf(pBVar6,"%02x",(uint)*pbVar10);
              } while (iVar12 < iVar3);
              local_1030 = local_1030 - iVar3;
              if (local_1030 < 1) goto LAB_0003eda8;
            }
            BIO_write(pBVar6,local_102c,iVar3);
            local_1030 = local_1030 - iVar3;
          } while (0 < local_1030);
        }
LAB_0003eda8:
        if (bVar1) {
          BIO_puts(pBVar6,"\n");
        }
        BIO_ctrl(pBVar6,0xb,0,(void *)0x0);
        uVar11 = 0;
        app_RAND_write_file(0,bio_err);
LAB_0003edc6:
        ERR_print_errors(bio_err);
        if (pBVar6 == (BIO *)0x0) goto LAB_0003ecc0;
      }
      BIO_free_all(pBVar6);
      goto LAB_0003ecc0;
    }
  }
  goto LAB_0003ecb6;
}

