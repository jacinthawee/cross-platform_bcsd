
undefined4 rand_main(undefined4 param_1,int param_2)

{
  byte *pbVar1;
  void *pvVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  BIO_METHOD *pBVar6;
  BIO *bp;
  int iVar7;
  ushort **ppuVar8;
  BIO *b;
  int iVar9;
  undefined4 uVar10;
  byte *pbVar11;
  byte *pbVar12;
  int in_GS_OFFSET;
  bool bVar13;
  bool bVar14;
  byte bVar15;
  int local_1044;
  void *local_1040;
  int local_1038;
  int local_1034;
  int local_1024;
  byte local_1020 [4096];
  int local_20;
  
  bVar15 = 0;
  local_1024 = -1;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar6 = BIO_s_file();
    bio_err = BIO_new(pBVar6);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar5 = load_config(bio_err,0);
  if (iVar5 != 0) {
    local_1038 = 0;
    bVar3 = false;
    local_1044 = 0;
    bVar4 = false;
    local_1034 = 0;
    local_1040 = (void *)0x0;
LAB_0808bddf:
    do {
      iVar5 = local_1044 + 1;
      pbVar1 = *(byte **)(param_2 + iVar5 * 4);
      iVar7 = iVar5 * 4;
      bVar13 = false;
      bVar14 = pbVar1 == (byte *)0x0;
      if (bVar14) {
        bVar13 = false;
        goto LAB_0808be31;
      }
      iVar9 = 5;
      pbVar11 = pbVar1;
      pbVar12 = &DAT_081ea8e1;
      do {
        if (iVar9 == 0) break;
        iVar9 = iVar9 + -1;
        bVar13 = *pbVar11 < *pbVar12;
        bVar14 = *pbVar11 == *pbVar12;
        pbVar11 = pbVar11 + (uint)bVar15 * -2 + 1;
        pbVar12 = pbVar12 + (uint)bVar15 * -2 + 1;
      } while (bVar14);
      bVar13 = (!bVar13 && !bVar14) == bVar13;
      if (bVar13) {
        pvVar2 = *(void **)(param_2 + 4 + iVar7);
        if ((local_1040 != (void *)0x0) || (pvVar2 == (void *)0x0)) goto LAB_0808be2c;
        local_1044 = local_1044 + 2;
        local_1040 = pvVar2;
        goto LAB_0808bddf;
      }
      iVar9 = 8;
      pbVar11 = pbVar1;
      pbVar12 = (byte *)"-engine";
      do {
        if (iVar9 == 0) break;
        iVar9 = iVar9 + -1;
        bVar13 = *pbVar11 == *pbVar12;
        pbVar11 = pbVar11 + (uint)bVar15 * -2 + 1;
        pbVar12 = pbVar12 + (uint)bVar15 * -2 + 1;
      } while (bVar13);
      if (bVar13) {
        iVar5 = *(int *)(param_2 + 4 + iVar7);
        if ((iVar5 == 0) || (local_1038 != 0)) goto LAB_0808be2c;
        local_1044 = local_1044 + 2;
        local_1038 = iVar5;
      }
      else {
        iVar9 = 6;
        pbVar11 = pbVar1;
        pbVar12 = (byte *)"-rand";
        do {
          if (iVar9 == 0) break;
          iVar9 = iVar9 + -1;
          bVar13 = *pbVar11 == *pbVar12;
          pbVar11 = pbVar11 + (uint)bVar15 * -2 + 1;
          pbVar12 = pbVar12 + (uint)bVar15 * -2 + 1;
        } while (bVar13);
        if (bVar13) {
          iVar5 = *(int *)(param_2 + 4 + iVar7);
          if ((local_1034 != 0) || (iVar5 == 0)) goto LAB_0808be2c;
          local_1044 = local_1044 + 2;
          local_1034 = iVar5;
        }
        else {
          iVar7 = 8;
          pbVar11 = pbVar1;
          pbVar12 = (byte *)0x81ecbc1;
          do {
            if (iVar7 == 0) break;
            iVar7 = iVar7 + -1;
            bVar13 = *pbVar11 == *pbVar12;
            pbVar11 = pbVar11 + (uint)bVar15 * -2 + 1;
            pbVar12 = pbVar12 + (uint)bVar15 * -2 + 1;
          } while (bVar13);
          local_1044 = iVar5;
          if (bVar13) {
            if (bVar4) goto LAB_0808be2c;
            bVar4 = true;
          }
          else {
            iVar5 = 5;
            pbVar11 = pbVar1;
            pbVar12 = &DAT_081ec27e;
            do {
              if (iVar5 == 0) break;
              iVar5 = iVar5 + -1;
              bVar13 = *pbVar11 == *pbVar12;
              pbVar11 = pbVar11 + (uint)bVar15 * -2 + 1;
              pbVar12 = pbVar12 + (uint)bVar15 * -2 + 1;
            } while (bVar13);
            if (bVar13) {
              if (bVar3) goto LAB_0808be2c;
              bVar3 = true;
            }
            else {
              ppuVar8 = __ctype_b_loc();
              if (((((*(byte *)((int)*ppuVar8 + (uint)*pbVar1 * 2 + 1) & 8) == 0) ||
                   (-1 < local_1024)) ||
                  (iVar5 = __isoc99_sscanf(pbVar1,"%d",&local_1024), iVar5 == 0)) ||
                 (local_1024 < 0)) goto LAB_0808be2c;
            }
          }
        }
      }
    } while( true );
  }
LAB_0808bece:
  uVar10 = 1;
  ERR_print_errors(bio_err);
LAB_0808bee4:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
LAB_0808be2c:
  bVar13 = true;
LAB_0808be31:
  if ((((bVar3) && (bVar4)) || (local_1024 < 0)) || (bVar13)) {
    BIO_printf(bio_err,"Usage: rand [options] num\n");
    BIO_printf(bio_err,"where options are\n");
    BIO_printf(bio_err,"-out file             - write to file\n");
    BIO_printf(bio_err,"-engine e             - use engine e, possibly a hardware device.\n");
    BIO_printf(bio_err,"-rand file%cfile%c... - seed PRNG from files\n",0x3a,0x3a);
    BIO_printf(bio_err,"-base64               - base64 encode output\n");
    BIO_printf(bio_err,"-hex                  - hex encode output\n");
  }
  else {
    setup_engine(bio_err,local_1038,0);
    app_RAND_load_file(0,bio_err,local_1034 != 0);
    if (local_1034 != 0) {
      uVar10 = app_RAND_load_files(local_1034);
      BIO_printf(bio_err,"%ld semi-random bytes loaded\n",uVar10);
    }
    pBVar6 = BIO_s_file();
    bp = BIO_new(pBVar6);
    if (bp != (BIO *)0x0) {
      if (local_1040 == (void *)0x0) {
        iVar5 = BIO_ctrl(bp,0x6a,0x10,stdout);
      }
      else {
        iVar5 = BIO_ctrl(bp,0x6c,5,local_1040);
      }
      if (iVar5 < 1) {
LAB_0808c271:
        uVar10 = 1;
        ERR_print_errors(bio_err);
      }
      else {
        if (bVar4) {
          pBVar6 = BIO_f_base64();
          b = BIO_new(pBVar6);
          if (b == (BIO *)0x0) goto LAB_0808c271;
          bp = BIO_push(b,bp);
        }
        if (0 < local_1024) {
          do {
            while( true ) {
              iVar5 = local_1024;
              if (0x1000 < local_1024) {
                iVar5 = 0x1000;
              }
              iVar7 = RAND_bytes(local_1020,iVar5);
              if (iVar7 < 1) {
                uVar10 = 1;
                goto LAB_0808c151;
              }
              iVar7 = 0;
              if (!bVar3) break;
              do {
                pbVar1 = local_1020 + iVar7;
                iVar7 = iVar7 + 1;
                BIO_printf(bp,"%02x",(uint)*pbVar1);
              } while (iVar7 < iVar5);
              local_1024 = local_1024 - iVar5;
              if (local_1024 < 1) goto LAB_0808c125;
            }
            BIO_write(bp,local_1020,iVar5);
            local_1024 = local_1024 - iVar5;
          } while (0 < local_1024);
        }
LAB_0808c125:
        if (bVar3) {
          BIO_puts(bp,"\n");
        }
        uVar10 = 0;
        BIO_ctrl(bp,0xb,0,(void *)0x0);
        app_RAND_write_file(0,bio_err);
LAB_0808c151:
        ERR_print_errors(bio_err);
        if (bp == (BIO *)0x0) goto LAB_0808bee4;
      }
      BIO_free_all(bp);
      goto LAB_0808bee4;
    }
  }
  goto LAB_0808bece;
}

