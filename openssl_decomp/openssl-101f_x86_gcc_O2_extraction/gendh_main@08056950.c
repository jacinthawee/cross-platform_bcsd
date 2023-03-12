
undefined4 gendh_main(int param_1,byte **param_2)

{
  byte *pbVar1;
  int iVar2;
  BIO_METHOD *pBVar3;
  BIO *bp;
  long lVar4;
  undefined4 uVar5;
  DH *dh;
  byte **ppbVar6;
  byte *__s;
  byte *pbVar7;
  byte *pbVar8;
  int in_GS_OFFSET;
  bool bVar9;
  bool bVar10;
  byte bVar11;
  int local_4c;
  int local_48;
  byte *local_44;
  byte *local_40;
  int local_30;
  BN_GENCB local_2c;
  int local_20;
  
  bVar11 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_30 = 0x200;
  signal(0xd,(__sighandler_t)0x1);
  local_2c.ver = 2;
  local_2c.cb.cb_1 = dh_cb;
  local_2c.arg = bio_err;
  if (bio_err == (BIO *)0x0) {
    pBVar3 = BIO_s_file();
    bio_err = BIO_new(pBVar3);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar2 = load_config(bio_err,0);
  if (iVar2 != 0) {
    local_4c = param_1 + -1;
    if (0 < local_4c) {
      local_40 = (byte *)0x0;
      local_44 = (byte *)0x0;
      bVar9 = false;
      __s = (byte *)0x0;
      bVar10 = true;
      local_48 = 2;
LAB_08056a01:
      ppbVar6 = param_2 + 1;
      pbVar1 = *ppbVar6;
      iVar2 = 5;
      pbVar7 = pbVar1;
      pbVar8 = &DAT_081ea8e1;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar9 = *pbVar7 < *pbVar8;
        bVar10 = *pbVar7 == *pbVar8;
        pbVar7 = pbVar7 + (uint)bVar11 * -2 + 1;
        pbVar8 = pbVar8 + (uint)bVar11 * -2 + 1;
      } while (bVar10);
      if ((!bVar9 && !bVar10) == bVar9) {
        local_4c = local_4c + -1;
        if (local_4c != 0) {
          __s = param_2[2];
          ppbVar6 = param_2 + 2;
          goto LAB_080569f4;
        }
      }
      else {
        bVar9 = *pbVar1 == 0x2d;
        if (bVar9) {
          if (pbVar1[1] == 0x32) {
            bVar9 = pbVar1[2] == 0;
            if (!bVar9) goto LAB_08056a28;
            local_48 = 2;
          }
          else {
            bVar9 = pbVar1[1] == 0x35;
            if ((!bVar9) || (bVar9 = pbVar1[2] == 0, !bVar9)) goto LAB_08056a28;
            local_48 = 5;
          }
LAB_080569f4:
          bVar9 = local_4c == 0;
          local_4c = local_4c + -1;
          bVar10 = local_4c == 0;
          param_2 = ppbVar6;
          if (bVar10) goto LAB_08056bc1;
          goto LAB_08056a01;
        }
LAB_08056a28:
        iVar2 = 8;
        pbVar7 = pbVar1;
        pbVar8 = (byte *)"-engine";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar9 = *pbVar7 == *pbVar8;
          pbVar7 = pbVar7 + (uint)bVar11 * -2 + 1;
          pbVar8 = pbVar8 + (uint)bVar11 * -2 + 1;
        } while (bVar9);
        if (bVar9) {
          local_4c = local_4c + -1;
          if (local_4c != 0) {
            ppbVar6 = param_2 + 2;
            local_40 = param_2[2];
            goto LAB_080569f4;
          }
        }
        else {
          iVar2 = 6;
          pbVar7 = pbVar1;
          pbVar8 = (byte *)"-rand";
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar9 = *pbVar7 == *pbVar8;
            pbVar7 = pbVar7 + (uint)bVar11 * -2 + 1;
            pbVar8 = pbVar8 + (uint)bVar11 * -2 + 1;
          } while (bVar9);
          if (bVar9) {
            local_4c = local_4c + -1;
            if (local_4c != 0) {
              ppbVar6 = param_2 + 2;
              local_44 = param_2[2];
              goto LAB_080569f4;
            }
            goto LAB_08056a6c;
          }
          iVar2 = __isoc99_sscanf(pbVar1,"%d",&local_30);
          if ((iVar2 != 0) && (-1 < local_30)) goto LAB_08056bc1;
        }
      }
LAB_08056a6c:
      BIO_printf(bio_err,"usage: gendh [args] [numbits]\n");
      BIO_printf(bio_err," -out file - output the key to \'file\n");
      BIO_printf(bio_err," -2        - use 2 as the generator value\n");
      BIO_printf(bio_err," -5        - use 5 as the generator value\n");
      BIO_printf(bio_err," -engine e - use engine e, possibly a hardware device.\n");
      BIO_printf(bio_err," -rand file%cfile%c...\n",0x3a,0x3a);
      BIO_printf(bio_err,"           - load the file (or the files in the directory) into\n");
      BIO_printf(bio_err,"             the random number generator\n");
      goto LAB_08056b03;
    }
    setup_engine(bio_err,0,0);
    pBVar3 = BIO_s_file();
    bp = BIO_new(pBVar3);
    if (bp != (BIO *)0x0) {
      local_44 = (byte *)0x0;
      local_48 = 2;
      goto LAB_08056d6c;
    }
    goto LAB_08056dd3;
  }
LAB_08056b03:
  uVar5 = 1;
  ERR_print_errors(bio_err);
LAB_08056b19:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
LAB_08056bc1:
  setup_engine(bio_err,local_40,0);
  pBVar3 = BIO_s_file();
  bp = BIO_new(pBVar3);
  if (bp != (BIO *)0x0) {
    if (__s == (byte *)0x0) {
LAB_08056d6c:
      BIO_ctrl(bp,0x6a,0,stdout);
LAB_08056c0d:
      iVar2 = app_RAND_load_file(0,bio_err,1);
      if (iVar2 == 0) {
        if (local_44 == (byte *)0x0) {
          BIO_printf(bio_err,
                     "warning, not much extra random data, consider using the -rand option\n");
        }
        else {
LAB_08056c36:
          uVar5 = app_RAND_load_files(local_44);
          BIO_printf(bio_err,"%ld semi-random bytes loaded\n",uVar5);
        }
      }
      else if (local_44 != (byte *)0x0) goto LAB_08056c36;
      BIO_printf(bio_err,"Generating DH parameters, %d bit long safe prime, generator %d\n",local_30
                 ,local_48);
      BIO_printf(bio_err,"This is going to take a long time\n");
      dh = DH_new();
      if ((dh != (DH *)0x0) &&
         (iVar2 = DH_generate_parameters_ex(dh,local_30,local_48,&local_2c), iVar2 != 0)) {
        app_RAND_write_file(0,bio_err);
        iVar2 = PEM_write_bio_DHparams(bp,dh);
        if (iVar2 != 0) {
          uVar5 = 0;
          goto LAB_08056cc3;
        }
      }
      uVar5 = 1;
      ERR_print_errors(bio_err);
    }
    else {
      lVar4 = BIO_ctrl(bp,0x6c,5,__s);
      if (0 < lVar4) goto LAB_08056c0d;
      uVar5 = 1;
      dh = (DH *)0x0;
      perror((char *)__s);
      ERR_print_errors(bio_err);
    }
LAB_08056cc3:
    BIO_free_all(bp);
    if (dh != (DH *)0x0) {
      DH_free(dh);
    }
    goto LAB_08056b19;
  }
LAB_08056dd3:
  ERR_print_errors(bio_err);
  goto LAB_08056b03;
}

