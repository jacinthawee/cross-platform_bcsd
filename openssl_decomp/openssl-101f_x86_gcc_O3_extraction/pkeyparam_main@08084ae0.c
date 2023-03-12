
undefined4 pkeyparam_main(undefined4 param_1,byte **param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  BIO *bp;
  BIO *bp_00;
  EVP_PKEY *x;
  byte **ppbVar5;
  byte *filename;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  undefined4 uVar9;
  bool bVar10;
  bool bVar11;
  byte bVar12;
  byte *local_2c;
  byte *local_28;
  
  bVar12 = 0;
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  iVar4 = load_config(bio_err,0);
  if (iVar4 != 0) {
    ERR_load_crypto_strings();
    OPENSSL_add_all_algorithms_noconf();
    local_28 = (byte *)0x0;
    bVar2 = false;
    filename = (byte *)0x0;
    local_2c = (byte *)0x0;
    bVar3 = false;
LAB_08084b5c:
    do {
      bVar1 = bVar3;
      ppbVar5 = param_2 + 1;
      pbVar7 = *ppbVar5;
      if ((pbVar7 == (byte *)0x0) || (*pbVar7 != 0x2d)) goto LAB_08084cd8;
      bVar10 = pbVar7[1] < 0x69;
      bVar11 = pbVar7[1] == 0x69;
      bVar3 = bVar1;
      if (bVar11) {
        bVar10 = pbVar7[2] < 0x6e;
        bVar11 = pbVar7[2] == 0x6e;
        if (!bVar11) goto LAB_08084b75;
        bVar10 = false;
        bVar11 = pbVar7[3] == 0;
        if (!bVar11) goto LAB_08084b75;
        local_2c = param_2[2];
        pbVar7 = local_2c;
      }
      else {
LAB_08084b75:
        iVar4 = 5;
        pbVar6 = pbVar7;
        pbVar8 = &DAT_081ea8e1;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar10 = *pbVar6 < *pbVar8;
          bVar11 = *pbVar6 == *pbVar8;
          pbVar6 = pbVar6 + (uint)bVar12 * -2 + 1;
          pbVar8 = pbVar8 + (uint)bVar12 * -2 + 1;
        } while (bVar11);
        bVar10 = (!bVar10 && !bVar11) == bVar10;
        if (bVar10) {
          filename = param_2[2];
          pbVar7 = filename;
        }
        else {
          iVar4 = 8;
          pbVar6 = pbVar7;
          pbVar8 = (byte *)"-engine";
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar10 = *pbVar6 == *pbVar8;
            pbVar6 = pbVar6 + (uint)bVar12 * -2 + 1;
            pbVar8 = pbVar8 + (uint)bVar12 * -2 + 1;
          } while (bVar10);
          if (!bVar10) {
            iVar4 = 6;
            pbVar6 = pbVar7;
            pbVar8 = (byte *)"-text";
            do {
              if (iVar4 == 0) break;
              iVar4 = iVar4 + -1;
              bVar10 = *pbVar6 == *pbVar8;
              pbVar6 = pbVar6 + (uint)bVar12 * -2 + 1;
              pbVar8 = pbVar8 + (uint)bVar12 * -2 + 1;
            } while (bVar10);
            param_2 = ppbVar5;
            if (bVar10) {
              bVar2 = true;
            }
            else {
              iVar4 = 7;
              pbVar6 = (byte *)"-noout";
              do {
                if (iVar4 == 0) break;
                iVar4 = iVar4 + -1;
                bVar10 = *pbVar7 == *pbVar6;
                pbVar7 = pbVar7 + (uint)bVar12 * -2 + 1;
                pbVar6 = pbVar6 + (uint)bVar12 * -2 + 1;
              } while (bVar10);
              bVar3 = true;
              if (!bVar10) {
                bVar3 = bVar1;
              }
            }
            goto LAB_08084b5c;
          }
          local_28 = param_2[2];
          pbVar7 = local_28;
        }
      }
      if (pbVar7 == (byte *)0x0) {
        BIO_printf(bio_err,"Usage pkeyparam [options]\n");
        BIO_printf(bio_err,"where options are\n");
        BIO_printf(bio_err,"-in file        input file\n");
        BIO_printf(bio_err,"-out file       output file\n");
        BIO_printf(bio_err,"-text           print parameters as text\n");
        BIO_printf(bio_err,"-noout          don\'t output encoded parameters\n");
        BIO_printf(bio_err,"-engine e       use engine e, possibly a hardware device.\n");
        return 1;
      }
      param_2 = param_2 + 2;
    } while( true );
  }
  uVar9 = 1;
  x = (EVP_PKEY *)0x0;
  bp_00 = (BIO *)0x0;
  bp = (BIO *)0x0;
LAB_08084c83:
  EVP_PKEY_free(x);
  BIO_free_all(bp_00);
  BIO_free(bp);
  return uVar9;
LAB_08084cd8:
  setup_engine(bio_err,local_28,0);
  if (local_2c == (byte *)0x0) {
    bp = BIO_new_fp(stdin,0);
  }
  else {
    bp = BIO_new_file((char *)local_2c,"r");
    if (bp == (BIO *)0x0) {
      uVar9 = 1;
      x = (EVP_PKEY *)0x0;
      bp_00 = (BIO *)0x0;
      BIO_printf(bio_err,"Can\'t open input file %s\n",local_2c);
      goto LAB_08084c83;
    }
  }
  if (filename == (byte *)0x0) {
    bp_00 = BIO_new_fp(stdout,0);
  }
  else {
    bp_00 = BIO_new_file((char *)filename,"w");
    if (bp_00 == (BIO *)0x0) {
      uVar9 = 1;
      x = (EVP_PKEY *)0x0;
      BIO_printf(bio_err,"Can\'t open output file %s\n",filename);
      goto LAB_08084c83;
    }
  }
  x = PEM_read_bio_Parameters(bp,(EVP_PKEY **)0x0);
  if (x == (EVP_PKEY *)0x0) {
    uVar9 = 1;
    BIO_printf(bio_err,"Error reading parameters\n");
    ERR_print_errors(bio_err);
  }
  else {
    if (!bVar1) {
      PEM_write_bio_Parameters(bp_00,x);
    }
    uVar9 = 0;
    if (bVar2) {
      EVP_PKEY_print_params(bp_00,x,0,(ASN1_PCTX *)0x0);
    }
  }
  goto LAB_08084c83;
}

