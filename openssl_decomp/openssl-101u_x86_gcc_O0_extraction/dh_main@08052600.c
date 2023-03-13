
undefined4 dh_main(int param_1,byte **param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  BIO_METHOD *pBVar9;
  BIO *a;
  BIO *bp;
  long lVar10;
  int iVar11;
  uint uVar12;
  uchar *to;
  uint uVar13;
  undefined4 uVar14;
  DH *x;
  byte **ppbVar15;
  byte *pbVar16;
  byte *pbVar17;
  int in_GS_OFFSET;
  bool bVar18;
  bool bVar19;
  byte bVar20;
  char *format;
  int local_58;
  int local_54;
  byte *local_4c;
  byte *local_48;
  byte *local_44;
  uint local_24;
  int local_20;
  
  bVar20 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar9 = BIO_s_file();
    bio_err = BIO_new(pBVar9);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar8 = load_config(bio_err,0);
  if (iVar8 == 0) {
LAB_0805297e:
    uVar14 = 1;
    goto LAB_08052983;
  }
  pbVar2 = *param_2;
  local_44 = (byte *)0x0;
  local_48 = (byte *)0x0;
  local_4c = (byte *)0x0;
  bVar6 = false;
  bVar7 = false;
  bVar5 = false;
  local_54 = 3;
  local_58 = 3;
  bVar4 = false;
  param_1 = param_1 + -1;
  bVar18 = param_1 == 0;
  if (0 < param_1) {
    do {
      ppbVar15 = param_2 + 1;
      pbVar3 = *ppbVar15;
      iVar8 = 8;
      pbVar16 = pbVar3;
      pbVar17 = (byte *)"-inform";
      do {
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        bVar18 = *pbVar16 == *pbVar17;
        pbVar16 = pbVar16 + (uint)bVar20 * -2 + 1;
        pbVar17 = pbVar17 + (uint)bVar20 * -2 + 1;
      } while (bVar18);
      if (bVar18) {
        param_1 = param_1 + -1;
        if (param_1 == 0) {
LAB_080528b0:
          BIO_printf(bio_err,"%s [options] <infile >outfile\n",pbVar2);
          BIO_printf(bio_err,"where options are\n");
          BIO_printf(bio_err," -inform arg   input format - one of DER PEM\n");
          BIO_printf(bio_err," -outform arg  output format - one of DER PEM\n");
          BIO_printf(bio_err," -in arg       input file\n");
          BIO_printf(bio_err," -out arg      output file\n");
          BIO_printf(bio_err," -check        check the DH parameters\n");
          BIO_printf(bio_err," -text         print a text form of the DH parameters\n");
          BIO_printf(bio_err," -C            Output C code\n");
          BIO_printf(bio_err," -noout        no output\n");
          BIO_printf(bio_err," -engine e     use engine e, possibly a hardware device.\n");
          goto LAB_0805297e;
        }
        ppbVar15 = param_2 + 2;
        local_58 = str2fmt(param_2[2]);
      }
      else {
        iVar8 = 9;
        pbVar16 = pbVar3;
        pbVar17 = (byte *)"-outform";
        do {
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          bVar18 = *pbVar16 == *pbVar17;
          pbVar16 = pbVar16 + (uint)bVar20 * -2 + 1;
          pbVar17 = pbVar17 + (uint)bVar20 * -2 + 1;
        } while (bVar18);
        if (bVar18) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_080528b0;
          ppbVar15 = param_2 + 2;
          local_54 = str2fmt(param_2[2]);
        }
        else {
          bVar1 = *pbVar3;
          bVar18 = 0x2d < bVar1;
          bVar19 = bVar1 == 0x2d;
          if (bVar19) {
            bVar18 = pbVar3[1] < 0x69;
            bVar19 = pbVar3[1] == 0x69;
            if (bVar19) {
              bVar18 = pbVar3[2] < 0x6e;
              bVar19 = pbVar3[2] == 0x6e;
              if (bVar19) {
                bVar18 = false;
                bVar19 = pbVar3[3] == 0;
                if (bVar19) {
                  param_1 = param_1 + -1;
                  if (param_1 == 0) goto LAB_080528b0;
                  local_4c = param_2[2];
                  ppbVar15 = param_2 + 2;
                  goto LAB_080527ce;
                }
              }
            }
          }
          iVar8 = 5;
          pbVar16 = pbVar3;
          pbVar17 = &DAT_081eab75;
          do {
            if (iVar8 == 0) break;
            iVar8 = iVar8 + -1;
            bVar18 = *pbVar16 < *pbVar17;
            bVar19 = *pbVar16 == *pbVar17;
            pbVar16 = pbVar16 + (uint)bVar20 * -2 + 1;
            pbVar17 = pbVar17 + (uint)bVar20 * -2 + 1;
          } while (bVar19);
          bVar18 = (!bVar18 && !bVar19) == bVar18;
          if (bVar18) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_080528b0;
            local_48 = param_2[2];
            ppbVar15 = param_2 + 2;
          }
          else {
            iVar8 = 8;
            pbVar16 = pbVar3;
            pbVar17 = (byte *)"-engine";
            do {
              if (iVar8 == 0) break;
              iVar8 = iVar8 + -1;
              bVar18 = *pbVar16 == *pbVar17;
              pbVar16 = pbVar16 + (uint)bVar20 * -2 + 1;
              pbVar17 = pbVar17 + (uint)bVar20 * -2 + 1;
            } while (bVar18);
            if (bVar18) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_080528b0;
              local_44 = param_2[2];
              ppbVar15 = param_2 + 2;
            }
            else {
              iVar8 = 7;
              pbVar16 = pbVar3;
              pbVar17 = (byte *)"-check";
              do {
                if (iVar8 == 0) break;
                iVar8 = iVar8 + -1;
                bVar18 = *pbVar16 == *pbVar17;
                pbVar16 = pbVar16 + (uint)bVar20 * -2 + 1;
                pbVar17 = pbVar17 + (uint)bVar20 * -2 + 1;
              } while (bVar18);
              if (bVar18) {
                bVar5 = true;
              }
              else {
                iVar8 = 6;
                pbVar16 = pbVar3;
                pbVar17 = (byte *)"-text";
                do {
                  if (iVar8 == 0) break;
                  iVar8 = iVar8 + -1;
                  bVar18 = *pbVar16 == *pbVar17;
                  pbVar16 = pbVar16 + (uint)bVar20 * -2 + 1;
                  pbVar17 = pbVar17 + (uint)bVar20 * -2 + 1;
                } while (bVar18);
                if (bVar18) {
                  bVar4 = true;
                }
                else {
                  bVar18 = bVar1 == 0x2d;
                  if (((bVar18) && (bVar18 = pbVar3[1] == 0x43, bVar18)) &&
                     (bVar18 = pbVar3[2] == 0, bVar18)) {
                    bVar6 = true;
                  }
                  else {
                    iVar8 = 7;
                    pbVar16 = pbVar3;
                    pbVar17 = (byte *)"-noout";
                    do {
                      if (iVar8 == 0) break;
                      iVar8 = iVar8 + -1;
                      bVar18 = *pbVar16 == *pbVar17;
                      pbVar16 = pbVar16 + (uint)bVar20 * -2 + 1;
                      pbVar17 = pbVar17 + (uint)bVar20 * -2 + 1;
                    } while (bVar18);
                    if (!bVar18) {
                      BIO_printf(bio_err,"unknown option %s\n",pbVar3);
                      goto LAB_080528b0;
                    }
                    bVar7 = true;
                  }
                }
              }
            }
          }
        }
      }
LAB_080527ce:
      param_1 = param_1 + -1;
      bVar18 = param_1 == 0;
      param_2 = ppbVar15;
    } while (!bVar18);
  }
  ERR_load_crypto_strings();
  setup_engine(bio_err,local_44,0);
  pBVar9 = BIO_s_file();
  a = BIO_new(pBVar9);
  pBVar9 = BIO_s_file();
  bp = BIO_new(pBVar9);
  if ((a == (BIO *)0x0) || (bp == (BIO *)0x0)) {
    ERR_print_errors(bio_err);
    if (a != (BIO *)0x0) {
      BIO_free(a);
    }
    if (bp == (BIO *)0x0) goto LAB_0805297e;
    x = (DH *)0x0;
    uVar14 = 1;
  }
  else {
    if (local_4c == (byte *)0x0) {
      BIO_ctrl(a,0x6a,0,stdin);
LAB_0805271f:
      if (local_48 == (byte *)0x0) {
        BIO_ctrl(bp,0x6a,0,stdout);
      }
      else {
        lVar10 = BIO_ctrl(bp,0x6c,5,local_48);
        if (lVar10 < 1) {
          uVar14 = 1;
          x = (DH *)0x0;
          perror((char *)local_48);
          goto LAB_08052777;
        }
      }
      if (local_58 == 1) {
        x = (DH *)ASN1_d2i_bio(DH_new,d2i_DHparams,a,(void **)0x0);
      }
      else {
        if (local_58 != 3) {
          uVar14 = 1;
          x = (DH *)0x0;
          BIO_printf(bio_err,"bad input format specified\n");
          goto LAB_08052777;
        }
        x = PEM_read_bio_DHparams(a,(DH **)0x0,(undefined1 *)0x0,(void *)0x0);
      }
      if (x == (DH *)0x0) {
        format = "unable to load DH parameters\n";
LAB_08052ea7:
        uVar14 = 1;
        BIO_printf(bio_err,format);
        ERR_print_errors(bio_err);
      }
      else {
        if (bVar4) {
          DHparams_print(bp,x);
        }
        if (bVar5) {
          iVar8 = DH_check(x,(int *)&local_24);
          if (iVar8 == 0) {
            uVar14 = 1;
            ERR_print_errors(bio_err);
            goto LAB_08052777;
          }
          if ((local_24 & 1) != 0) {
            puts("p value is not prime");
          }
          if ((local_24 & 2) != 0) {
            puts("p value is not a safe prime");
          }
          if ((local_24 & 4) != 0) {
            puts("unable to check the generator value");
          }
          if ((local_24 & 8) != 0) {
            puts("the g value is not a generator");
          }
          if (local_24 == 0) {
            puts("DH parameters appear to be ok.");
          }
        }
        if (bVar6) {
          iVar11 = BN_num_bits(x->p);
          uVar12 = BN_num_bits(x->p);
          iVar8 = iVar11 + 0xe;
          if (-1 < iVar11 + 7) {
            iVar8 = iVar11 + 7;
          }
          to = (uchar *)CRYPTO_malloc(iVar8 >> 3,"dh.c",0x10d);
          if (to == (uchar *)0x0) {
            uVar14 = 1;
            perror("OPENSSL_malloc");
            goto LAB_08052777;
          }
          iVar8 = BN_bn2bin(x->p,to);
          uVar13 = uVar12;
          __printf_chk(1,"static unsigned char dh%d_p[]={",uVar12);
          local_24 = 0;
          if (0 < iVar8) {
            do {
              if (local_24 ==
                  (((int)local_24 / 6 + ((int)local_24 >> 0x1f) >> 1) - ((int)local_24 >> 0x1f)) *
                  0xc) {
                __printf_chk(1,&DAT_081ec75e,uVar13);
              }
              uVar13 = (uint)to[local_24];
              __printf_chk(1,"0x%02X,",uVar13);
              local_24 = local_24 + 1;
            } while ((int)local_24 < iVar8);
          }
          puts("\n\t};");
          iVar8 = BN_bn2bin(x->g,to);
          uVar13 = uVar12;
          __printf_chk(1,"static unsigned char dh%d_g[]={",uVar12);
          local_24 = 0;
          if (0 < iVar8) {
            do {
              if (local_24 ==
                  (((int)local_24 / 6 + ((int)local_24 >> 0x1f) >> 1) - ((int)local_24 >> 0x1f)) *
                  0xc) {
                __printf_chk(1,&DAT_081ec75e,uVar13);
              }
              uVar13 = (uint)to[local_24];
              __printf_chk(1,"0x%02X,",uVar13);
              local_24 = local_24 + 1;
            } while ((int)local_24 < iVar8);
          }
          puts("\n\t};\n");
          __printf_chk(1,"DH *get_dh%d()\n\t{\n",uVar12);
          puts("\tDH *dh;\n");
          puts("\tif ((dh=DH_new()) == NULL) return(NULL);");
          __printf_chk(1,"\tdh->p=BN_bin2bn(dh%d_p,sizeof(dh%d_p),NULL);\n",uVar12,uVar12);
          __printf_chk(1,"\tdh->g=BN_bin2bn(dh%d_g,sizeof(dh%d_g),NULL);\n",uVar12,uVar12);
          puts("\tif ((dh->p == NULL) || (dh->g == NULL))");
          puts("\t\treturn(NULL);");
          puts("\treturn(dh);\n\t}");
          CRYPTO_free(to);
        }
        uVar14 = 0;
        if (!bVar7) {
          if (local_54 == 1) {
            local_24 = ASN1_i2d_bio(i2d_DHparams,bp,(uchar *)x);
          }
          else {
            if (local_54 != 3) {
              uVar14 = 1;
              BIO_printf(bio_err,"bad output format specified for outfile\n");
              goto LAB_08052777;
            }
            local_24 = PEM_write_bio_DHparams(bp,x);
          }
          uVar14 = 0;
          if (local_24 == 0) {
            format = "unable to write DH parameters\n";
            goto LAB_08052ea7;
          }
        }
      }
    }
    else {
      lVar10 = BIO_ctrl(a,0x6c,3,local_4c);
      if (0 < lVar10) goto LAB_0805271f;
      uVar14 = 1;
      x = (DH *)0x0;
      perror((char *)local_4c);
    }
LAB_08052777:
    BIO_free(a);
  }
  BIO_free_all(bp);
  if (x != (DH *)0x0) {
    DH_free(x);
  }
LAB_08052983:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar14;
}

