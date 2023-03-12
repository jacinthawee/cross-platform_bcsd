
/* WARNING: Type propagation algorithm not settling */

undefined4 req_main(int param_1,undefined4 *param_2)

{
  byte bVar1;
  bool bVar2;
  byte *pbVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  undefined *puVar13;
  undefined *puVar14;
  undefined *puVar15;
  char *pcVar16;
  undefined4 uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  uint uVar24;
  int iVar25;
  byte *pbVar26;
  int iVar27;
  char *pcVar28;
  undefined4 *puVar29;
  byte bVar30;
  char **ppcVar31;
  int *piVar32;
  byte *pbVar33;
  char **ppcVar34;
  char *pcVar35;
  int iVar36;
  undefined4 uVar37;
  int *piVar38;
  char *pcVar39;
  code *pcVar40;
  undefined4 uVar41;
  char *local_578;
  int local_570;
  undefined4 *local_564;
  char *local_560;
  char *local_55c;
  undefined4 *local_558;
  int local_554;
  int local_54c;
  char *local_548;
  char *local_53c;
  char *local_538;
  int local_534;
  char *local_52c;
  char *local_528;
  char *local_520;
  char *local_51c;
  char *local_518;
  char *local_514;
  int local_508;
  int local_504;
  char *local_500;
  undefined4 local_4fc;
  int local_4ec;
  int local_4e8;
  char *local_4e4;
  undefined4 local_4e0;
  char *local_4dc;
  char *local_4d4;
  undefined4 local_4d0;
  undefined4 local_4cc;
  int local_4c8;
  int local_4c4;
  int local_4c0;
  int local_4bc;
  int local_4b8;
  int local_4b4;
  char *local_4b0;
  undefined4 local_4ac [7];
  undefined auStack_490 [99];
  char acStack_42d [1025];
  int local_2c;
  
  puVar15 = PTR___stack_chk_guard_006aabf0;
  puVar13 = PTR_bio_err_006a7f3c;
  local_4c0 = -1;
  local_4bc = -1;
  req_conf = 0;
  local_4d0 = 0;
  local_4cc = 0;
  local_4c8 = 0;
  local_4c4 = 0;
  local_4b8 = 0;
  local_4b4 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_508 = (*(code *)PTR_EVP_des_ede3_cbc_006a7f48)();
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  if (*(int *)puVar13 == 0) {
    uVar17 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar19 = (*(code *)PTR_BIO_new_006a7fa4)(uVar17);
    *(int *)puVar13 = iVar19;
    if (iVar19 != 0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar19,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
    }
  }
  uVar17 = *param_2;
  param_1 = param_1 + -1;
  ppcVar31 = (char **)(param_2 + 1);
  local_534 = 0x1001;
  if (param_1 < 1) {
    local_4fc = 0;
    local_520 = (char *)0x0;
    pcVar39 = (char *)0x3;
    local_55c = (char *)0x0;
    piVar38 = (int *)0x3;
    local_4e0 = 3;
    local_560 = (char *)0x0;
    local_4d4 = (char *)0x0;
    bVar9 = false;
    local_554 = 0;
    local_528 = (char *)0x0;
    local_52c = (char *)0x0;
    local_578 = (char *)0x0;
    local_51c = (char *)0x0;
    local_53c = (char *)0x0;
    local_548 = (char *)0x0;
    local_514 = (char *)0x0;
    local_500 = (char *)0x0;
    bVar11 = false;
    bVar10 = false;
    bVar12 = false;
    bVar4 = false;
    local_4dc = (char *)0x0;
    bVar8 = false;
    bVar7 = false;
    bVar6 = false;
    local_518 = (char *)0x0;
    local_538 = (char *)0x0;
    local_558 = (undefined4 *)0x0;
    local_564 = (undefined4 *)0x0;
    local_4e4 = (char *)0x0;
    local_4e8 = 0x1e;
    bVar5 = false;
    local_570 = 0;
    local_504 = 0;
    local_4ec = 0;
  }
  else {
    local_504 = 0;
    local_4ec = 0;
    local_4fc = 0;
    local_4e0 = 3;
    local_520 = (char *)0x0;
    pcVar39 = (char *)0x3;
    local_55c = (char *)0x0;
    piVar38 = (int *)0x3;
    local_4e8 = 0x1e;
    local_560 = (char *)0x0;
    local_4d4 = (char *)0x0;
    bVar9 = false;
    local_554 = 0;
    local_528 = (char *)0x0;
    local_52c = (char *)0x0;
    local_578 = (char *)0x0;
    local_51c = (char *)0x0;
    local_53c = (char *)0x0;
    local_548 = (char *)0x0;
    local_514 = (char *)0x0;
    local_500 = (char *)0x0;
    bVar11 = false;
    bVar10 = false;
    bVar12 = false;
    bVar4 = false;
    local_4dc = (char *)0x0;
    bVar8 = false;
    bVar7 = false;
    bVar6 = false;
    local_518 = (char *)0x0;
    local_538 = (char *)0x0;
    local_558 = (undefined4 *)0x0;
    local_564 = (undefined4 *)0x0;
    local_4e4 = (char *)0x0;
    bVar5 = false;
    local_570 = 0;
LAB_004244b8:
    do {
      pcVar35 = *ppcVar31;
      iVar18 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-inform");
      iVar19 = local_504;
      if (iVar18 == 0) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          piVar38 = (int *)(*(code *)PTR_str2fmt_006a7f4c)(ppcVar31[1]);
          ppcVar34 = ppcVar31 + 1;
          goto LAB_004244ac;
        }
LAB_0042486c:
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,"%s [options] <infile >outfile\n",uVar17);
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"where options  are\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -inform arg    input format - DER or PEM\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -outform arg   output format - DER or PEM\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13," -in arg        input file\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13," -out arg       output file\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -text          text form of request\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -pubkey        output public key\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -noout         do not output REQ\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -verify        verify signature on REQ\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13," -modulus       RSA modulus\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -nodes         don\'t encrypt the output key\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -engine e      use engine e, possibly a hardware device\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -subject       output the request\'s subject\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -passin        private key password source\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -key file      use the private key contained in file\n")
        ;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -keyform arg   key file format\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -keyout arg    file to send the key to\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -rand file%cfile%c...\n",0x3a,0x3a);
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   "                load the file (or the files in the directory) into\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,"                the random number generator\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -newkey rsa:bits generate a new RSA key of \'bits\' in size\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -newkey dsa:file generate a new DSA key, parameters taken from CA in \'file\'\n"
                  );
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -newkey ec:file generate a new EC key, parameters taken from CA in \'file\'\n")
        ;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -[digest]      Digest to sign with (md5, sha1, md2, mdc2, md4)\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -config file   request template file.\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -subj arg      set or modify request subject\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -multivalue-rdn enable support for multivalued RDNs\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13," -new           new request.\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -batch         do not ask anything during request generation\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -x509          output a x509 structure instead of a cert. req.\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -days          number of days a certificate generated by -x509 is valid for.\n"
                  );
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -set_serial    serial number to use for a certificate generated by -x509.\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -newhdr        output \"NEW\" in the header lines\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -asn1-kludge   Output the \'request\' in a format that is wrong but some CA\'s\n"
                  );
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,"                have been reported as requiring\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -extensions .. specify certificate extension section (override value in config file)\n"
                  );
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -reqexts ..    specify request extension section (override value in config file)\n"
                  );
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -utf8          input characters are UTF8 (default ASCII)\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -nameopt arg    - various certificate name options\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -reqopt arg    - various request text options\n\n");
        goto LAB_00424810;
      }
      iVar18 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-outform");
      if (iVar18 != 0) {
        iVar18 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-engine");
        if (iVar18 == 0) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_0042486c;
          local_578 = ppcVar31[1];
          ppcVar34 = ppcVar31 + 1;
        }
        else {
          iVar18 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-keygen_engine");
          if (iVar18 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_0042486c;
            local_570 = (*(code *)PTR_ENGINE_by_id_006a7f9c)(ppcVar31[1]);
            ppcVar34 = ppcVar31 + 1;
            if (local_570 == 0) {
              pcVar35 = ppcVar31[1];
              uVar17 = *(undefined4 *)puVar13;
              pcVar28 = "Can\'t find keygen engine %s\n";
              goto LAB_00424804;
            }
          }
          else {
            iVar18 = (*(code *)PTR_strcmp_006aac20)(pcVar35,&DAT_006330b4);
            if (iVar18 == 0) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_0042486c;
              local_548 = ppcVar31[1];
              ppcVar34 = ppcVar31 + 1;
            }
            else {
              iVar18 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-pubkey");
              ppcVar34 = ppcVar31;
              if (iVar18 == 0) {
                bVar11 = true;
              }
              else {
                iVar18 = (*(code *)PTR_strcmp_006aac20)(pcVar35,&DAT_006330c4);
                if (iVar18 == 0) {
                  local_538 = (char *)0x1;
                }
                else {
                  iVar18 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-config");
                  if (iVar18 == 0) {
                    param_1 = param_1 + -1;
                    if (param_1 == 0) goto LAB_0042486c;
                    local_53c = ppcVar31[1];
                    ppcVar34 = ppcVar31 + 1;
                  }
                  else {
                    iVar18 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-keyform");
                    if (iVar18 == 0) {
                      param_1 = param_1 + -1;
                      if (param_1 == 0) goto LAB_0042486c;
                      local_4e0 = (*(code *)PTR_str2fmt_006a7f4c)(ppcVar31[1]);
                      ppcVar34 = ppcVar31 + 1;
                    }
                    else if ((((*pcVar35 == '-') && (pcVar35[1] == 'i')) && (pcVar35[2] == 'n')) &&
                            (pcVar35[3] == '\0')) {
                      param_1 = param_1 + -1;
                      if (param_1 == 0) goto LAB_0042486c;
                      local_500 = ppcVar31[1];
                      ppcVar34 = ppcVar31 + 1;
                    }
                    else {
                      iVar18 = (*(code *)PTR_strcmp_006aac20)(pcVar35,&DAT_00632edc);
                      if (iVar18 == 0) {
                        param_1 = param_1 + -1;
                        if (param_1 == 0) goto LAB_0042486c;
                        local_514 = ppcVar31[1];
                        ppcVar34 = ppcVar31 + 1;
                      }
                      else {
                        iVar18 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-keyout");
                        if (iVar18 == 0) {
                          param_1 = param_1 + -1;
                          if (param_1 == 0) goto LAB_0042486c;
                          local_51c = ppcVar31[1];
                          ppcVar34 = ppcVar31 + 1;
                        }
                        else {
                          iVar18 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-passin");
                          if (iVar18 == 0) {
                            param_1 = param_1 + -1;
                            if (param_1 == 0) goto LAB_0042486c;
                            local_560 = ppcVar31[1];
                            ppcVar34 = ppcVar31 + 1;
                          }
                          else {
                            iVar18 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-passout");
                            if (iVar18 == 0) {
                              param_1 = param_1 + -1;
                              if (param_1 == 0) goto LAB_0042486c;
                              local_55c = ppcVar31[1];
                              ppcVar34 = ppcVar31 + 1;
                            }
                            else {
                              iVar18 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-rand");
                              if (iVar18 == 0) {
                                param_1 = param_1 + -1;
                                if (param_1 == 0) goto LAB_0042486c;
                                local_4d4 = ppcVar31[1];
                                ppcVar34 = ppcVar31 + 1;
                              }
                              else {
                                iVar18 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-newkey");
                                if (iVar18 != 0) {
                                  iVar18 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-pkeyopt");
                                  if (iVar18 == 0) {
                                    if (param_1 != 1) {
                                      puVar29 = local_564;
                                      pcVar40 = (code *)PTR_sk_push_006a80a8;
                                      if (local_564 == (undefined4 *)0x0) {
                                        puVar29 = (undefined4 *)
                                                  (*(code *)PTR_sk_new_null_006a80a4)();
                                        local_564 = puVar29;
                                        pcVar40 = (code *)PTR_sk_push_006a80a8;
joined_r0x00427474:
                                        PTR_sk_push_006a80a8 = pcVar40;
                                        if (puVar29 == (undefined4 *)0x0) goto LAB_0042486c;
                                      }
LAB_004273f0:
                                      iVar18 = (*pcVar40)(puVar29,ppcVar31[1]);
joined_r0x004277bc:
                                      param_1 = param_1 + -1;
                                      ppcVar34 = ppcVar31 + 1;
                                      if (iVar18 != 0) goto LAB_004244ac;
                                    }
                                  }
                                  else {
                                    iVar18 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-sigopt");
                                    if (iVar18 != 0) {
                                      iVar18 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-batch");
                                      if (iVar18 == 0) {
                                        batch = 1;
                                      }
                                      else {
                                        iVar18 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-newhdr");
                                        if (iVar18 == 0) {
                                          bVar12 = true;
                                        }
                                        else {
                                          iVar18 = (*(code *)PTR_strcmp_006aac20)
                                                             (pcVar35,"-modulus");
                                          if (iVar18 == 0) {
                                            bVar9 = true;
                                          }
                                          else {
                                            iVar18 = (*(code *)PTR_strcmp_006aac20)
                                                               (pcVar35,"-verify");
                                            if (iVar18 == 0) {
                                              bVar6 = true;
                                            }
                                            else {
                                              iVar18 = (*(code *)PTR_strcmp_006aac20)
                                                                 (pcVar35,"-nodes");
                                              if (iVar18 == 0) {
                                                local_4dc = (char *)0x1;
                                              }
                                              else {
                                                iVar18 = (*(code *)PTR_strcmp_006aac20)
                                                                   (pcVar35,"-noout");
                                                if (iVar18 == 0) {
                                                  bVar7 = true;
                                                }
                                                else {
                                                  iVar18 = (*(code *)PTR_strcmp_006aac20)
                                                                     (pcVar35,"-verbose");
                                                  if (iVar18 == 0) {
                                                    local_518 = (char *)0x1;
                                                  }
                                                  else {
                                                    iVar18 = (*(code *)PTR_strcmp_006aac20)
                                                                       (pcVar35,"-utf8");
                                                    if (iVar18 != 0) {
                                                      iVar18 = (*(code *)PTR_strcmp_006aac20)
                                                                         (pcVar35,"-nameopt");
                                                      if (iVar18 == 0) {
                                                        if (param_1 != 1) {
                                                          puVar29 = &local_4d0;
                                                          pcVar40 = (code *)PTR_set_name_ex_006a80ac
                                                          ;
                                                          goto LAB_004273f0;
                                                        }
                                                      }
                                                      else {
                                                        iVar18 = (*(code *)PTR_strcmp_006aac20)
                                                                           (pcVar35,"-reqopt");
                                                        if (iVar18 != 0) {
                                                          iVar18 = (*(code *)PTR_strcmp_006aac20)
                                                                             (pcVar35,"-subject");
                                                          if (iVar18 == 0) {
                                                            bVar10 = true;
                                                          }
                                                          else {
                                                            iVar18 = (*(code *)PTR_strcmp_006aac20)
                                                                               (pcVar35,"-text");
                                                            if (iVar18 == 0) {
                                                              bVar8 = true;
                                                            }
                                                            else {
                                                              iVar18 = (*(code *)PTR_strcmp_006aac20
                                                                       )(pcVar35,"-x509");
                                                              if (iVar18 == 0) {
                                                                bVar5 = true;
                                                              }
                                                              else {
                                                                iVar18 = (*(code *)
                                                  PTR_strcmp_006aac20)(pcVar35,"-asn1-kludge");
                                                  if (iVar18 == 0) {
                                                    bVar4 = true;
                                                  }
                                                  else {
                                                    iVar18 = (*(code *)PTR_strcmp_006aac20)
                                                                       (pcVar35,"-no-asn1-kludge");
                                                    if (iVar18 == 0) {
                                                      bVar4 = false;
                                                    }
                                                    else {
                                                      iVar18 = (*(code *)PTR_strcmp_006aac20)
                                                                         (pcVar35,"-subj");
                                                      if (iVar18 == 0) {
                                                        param_1 = param_1 + -1;
                                                        if (param_1 == 0) goto LAB_0042486c;
                                                        local_520 = ppcVar31[1];
                                                        ppcVar34 = ppcVar31 + 1;
                                                      }
                                                      else {
                                                        iVar18 = (*(code *)PTR_strcmp_006aac20)
                                                                           (pcVar35,
                                                  "-multivalue-rdn");
                                                  if (iVar18 == 0) {
                                                    local_4fc = 1;
                                                  }
                                                  else {
                                                    iVar18 = (*(code *)PTR_strcmp_006aac20)
                                                                       (pcVar35,"-days");
                                                    if (iVar18 == 0) {
                                                      param_1 = param_1 + -1;
                                                      if (param_1 == 0) goto LAB_0042486c;
                                                      ppcVar34 = ppcVar31 + 1;
                                                      iVar18 = (*(code *)PTR_strtol_006aaa68)
                                                                         (ppcVar31[1],0,10);
                                                      local_4e8 = 0x1e;
                                                      if (iVar18 != 0) {
                                                        local_4e8 = iVar18;
                                                      }
                                                    }
                                                    else {
                                                      iVar18 = (*(code *)PTR_strcmp_006aac20)
                                                                         (pcVar35,"-set_serial");
                                                      if (iVar18 == 0) {
                                                        if (param_1 == 1) goto LAB_0042486c;
                                                        local_554 = (*(code *)
                                                  PTR_s2i_ASN1_INTEGER_006a80b4)(0,ppcVar31[1]);
                                                  iVar18 = local_554;
                                                  goto joined_r0x004277bc;
                                                  }
                                                  iVar18 = (*(code *)PTR_strcmp_006aac20)
                                                                     (pcVar35,"-extensions");
                                                  if (iVar18 == 0) {
                                                    param_1 = param_1 + -1;
                                                    if (param_1 == 0) goto LAB_0042486c;
                                                    local_52c = ppcVar31[1];
                                                    ppcVar34 = ppcVar31 + 1;
                                                  }
                                                  else {
                                                    iVar18 = (*(code *)PTR_strcmp_006aac20)
                                                                       (pcVar35,"-reqexts");
                                                    if (iVar18 == 0) {
                                                      param_1 = param_1 + -1;
                                                      if (param_1 == 0) goto LAB_0042486c;
                                                      local_528 = ppcVar31[1];
                                                      ppcVar34 = ppcVar31 + 1;
                                                    }
                                                    else {
                                                      local_4ec = (*(code *)
                                                  PTR_EVP_get_digestbyname_006a802c)(pcVar35 + 1);
                                                  iVar19 = local_4ec;
                                                  if (local_4ec == 0) {
                                                    (*(code *)PTR_BIO_printf_006a7f38)
                                                              (*(undefined4 *)puVar13,
                                                               "unknown option %s\n",*ppcVar31);
                                                    goto LAB_0042486c;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_004244ac;
                                                  }
                                                  if (param_1 != 1) {
                                                    puVar29 = &local_4cc;
                                                    pcVar40 = (code *)PTR_set_cert_ex_006a80b0;
                                                    goto LAB_004273f0;
                                                  }
                                                  }
                                                  goto LAB_0042486c;
                                                  }
                                                  local_534 = 0x1000;
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                      goto LAB_004244ac;
                                    }
                                    if (param_1 != 1) {
                                      puVar29 = local_558;
                                      pcVar40 = (code *)PTR_sk_push_006a80a8;
                                      if (local_558 == (undefined4 *)0x0) {
                                        puVar29 = (undefined4 *)
                                                  (*(code *)PTR_sk_new_null_006a80a4)();
                                        local_558 = puVar29;
                                        pcVar40 = (code *)PTR_sk_push_006a80a8;
                                        goto joined_r0x00427474;
                                      }
                                      goto LAB_004273f0;
                                    }
                                  }
                                  goto LAB_0042486c;
                                }
                                param_1 = param_1 + -1;
                                if (param_1 == 0) goto LAB_0042486c;
                                local_4e4 = ppcVar31[1];
                                local_538 = (char *)0x1;
                                ppcVar34 = ppcVar31 + 1;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
LAB_004244ac:
        local_504 = iVar19;
        param_1 = param_1 + -1;
        ppcVar31 = ppcVar34 + 1;
        if (param_1 == 0) break;
        goto LAB_004244b8;
      }
      if (param_1 == 1) goto LAB_0042486c;
      ppcVar34 = ppcVar31 + 1;
      param_1 = param_1 + -2;
      ppcVar31 = ppcVar31 + 2;
      pcVar39 = (char *)(*(code *)PTR_str2fmt_006a7f4c)(*ppcVar34);
    } while (param_1 != 0);
  }
  puVar14 = PTR_bio_err_006a7f3c;
  (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
  iVar19 = (*(code *)PTR_app_passwd_006a7f54)
                     (*(undefined4 *)puVar13,local_560,local_55c,&local_4b8,&local_4b4);
  if (iVar19 == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar14,"Error getting passwords\n");
  }
  else {
    if (local_53c == (char *)0x0) {
      req_conf = *(int *)PTR_config_006a7f68;
      if (req_conf == 0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar14,"Unable to load config info from %s\n",
                   *(undefined4 *)PTR_default_config_file_006a7fdc);
        if (local_538 != (char *)0x0) {
          iVar18 = 0;
          iVar19 = 0;
          goto LAB_004245d0;
        }
LAB_004245a4:
        if (req_conf != 0) goto LAB_004245b8;
LAB_00424e24:
        iVar19 = (*(code *)PTR_add_oid_section_006a7f60)(*(undefined4 *)puVar13,req_conf);
        if (iVar19 != 0) {
          if (local_4ec == 0) {
            iVar19 = (*(code *)PTR_NCONF_get_string_006a7fa8)(req_conf,&DAT_00632464,"default_md");
            if (iVar19 == 0) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            else {
              iVar19 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(iVar19);
              if (iVar19 != 0) {
                local_504 = iVar19;
              }
            }
          }
          if ((local_52c == (char *)0x0) &&
             (local_52c = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                            (req_conf,&DAT_00632464,"x509_extensions"),
             local_52c == (char *)0x0)) {
            (*(code *)PTR_ERR_clear_error_006a7fe0)();
LAB_00424eb4:
            piVar32 = (int *)0x630000;
            if ((local_4b8 == 0) &&
               (local_4b8 = (*(code *)PTR_NCONF_get_string_006a7fa8)
                                      (req_conf,&DAT_00632464,"input_password"), local_4b8 == 0)) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            if ((local_4b4 == 0) &&
               (local_4b4 = (*(code *)PTR_NCONF_get_string_006a7fa8)
                                      (req_conf,&DAT_00632464,"output_password"), local_4b4 == 0)) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            pcVar35 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                        (req_conf,&DAT_00632464,"string_mask");
            if (pcVar35 == (char *)0x0) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            else {
              iVar19 = (*(code *)PTR_ASN1_STRING_set_default_mask_asc_006a7fc0)(pcVar35);
              if (iVar19 == 0) {
                uVar17 = *(undefined4 *)puVar13;
                pcVar28 = "Invalid global string mask setting %s\n";
                goto LAB_00424804;
              }
            }
            if (local_534 == 0x1000) {
LAB_00424f6c:
              local_534 = 0x1000;
            }
            else {
              pcVar35 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                          (req_conf,&DAT_00632464,&DAT_00633b60);
              if (pcVar35 == (char *)0x0) {
                (*(code *)PTR_ERR_clear_error_006a7fe0)();
              }
              else if ((((*pcVar35 == 'y') && (pcVar35[1] == 'e')) && (pcVar35[2] == 's')) &&
                      (pcVar35[3] == '\0')) goto LAB_00424f6c;
            }
            if ((local_528 == (char *)0x0) &&
               (local_528 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                              (req_conf,&DAT_00632464,"req_extensions"),
               local_528 == (char *)0x0)) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            else {
              (*(code *)PTR_X509V3_set_ctx_006a7fb4)(local_4ac,0,0,0,0,1);
              (*(code *)PTR_X509V3_set_nconf_006a7fb8)(local_4ac,req_conf);
              iVar19 = (*(code *)PTR_X509V3_EXT_add_nconf_006a7fbc)(req_conf,local_4ac,local_528,0);
              if (iVar19 == 0) {
                uVar17 = *(undefined4 *)puVar13;
                pcVar28 = "Error Loading request extension section %s\n";
                pcVar35 = local_528;
                goto LAB_00424804;
              }
            }
            uVar17 = (*(code *)PTR_BIO_s_file_006a7fa0)();
            iVar19 = (*(code *)PTR_BIO_new_006a7fa4)(uVar17);
            uVar17 = (*(code *)PTR_BIO_s_file_006a7fa0)();
            iVar18 = (*(code *)PTR_BIO_new_006a7fa4)(uVar17);
            if ((iVar19 != 0) && (iVar18 != 0)) {
              uVar17 = (*(code *)PTR_setup_engine_006a7fc4)(*(undefined4 *)puVar13,local_578,0);
              if (local_548 == (char *)0x0) goto LAB_004250cc;
              local_4c4 = (*(code *)PTR_load_key_006a7fc8)
                                    (*(undefined4 *)PTR_bio_err_006a7f3c,local_548,local_4e0,0,
                                     local_4b8,uVar17,"Private Key");
              if (local_4c4 != 0) {
                iVar36 = (*(code *)PTR_NCONF_get_string_006a7fa8)(req_conf,&DAT_00632464,"RANDFILE")
                ;
                if (iVar36 == 0) goto LAB_00425c50;
                goto LAB_004250b4;
              }
            }
            goto LAB_004245d0;
          }
          (*(code *)PTR_X509V3_set_ctx_006a7fb4)(local_4ac,0,0,0,0,1);
          (*(code *)PTR_X509V3_set_nconf_006a7fb8)(local_4ac,req_conf);
          iVar19 = (*(code *)PTR_X509V3_EXT_add_nconf_006a7fbc)(req_conf,local_4ac,local_52c,0);
          if (iVar19 != 0) goto LAB_00424eb4;
          uVar17 = *(undefined4 *)puVar13;
          pcVar28 = "Error Loading extension section %s\n";
          pcVar35 = local_52c;
LAB_00424804:
          (*(code *)PTR_BIO_printf_006a7f38)(uVar17,pcVar28,pcVar35);
          goto LAB_00424810;
        }
      }
      else {
        if (local_518 != (char *)0x0) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar14,"Using configuration from %s\n",
                     *(undefined4 *)PTR_default_config_file_006a7fdc);
          goto LAB_004245a4;
        }
LAB_004245b8:
        iVar19 = (*(code *)PTR_load_config_006a7f64)(*(undefined4 *)puVar13);
        if (iVar19 != 0) {
          iVar19 = (*(code *)PTR_NCONF_get_string_006a7fa8)(req_conf,0,"oid_file");
          if (iVar19 == 0) {
            (*(code *)PTR_ERR_clear_error_006a7fe0)();
          }
          else {
            iVar19 = (*(code *)PTR_BIO_new_file_006a7fac)(iVar19,"r");
            if (iVar19 != 0) {
              (*(code *)PTR_OBJ_create_objects_006a7fb0)(iVar19);
              (*(code *)PTR_BIO_free_006a7f70)(iVar19);
            }
          }
          goto LAB_00424e24;
        }
      }
      iVar18 = 0;
      iVar19 = 0;
      goto LAB_004245d0;
    }
    local_4ac[0] = 0xffffffff;
    if (local_518 != (char *)0x0) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar14,"Using configuration from %s\n",local_53c);
    }
    req_conf = (*(code *)PTR_NCONF_new_006a7f58)(0);
    iVar19 = (*(code *)PTR_NCONF_load_006a7f5c)(req_conf,local_53c,local_4ac);
    if (iVar19 != 0) goto LAB_004245a4;
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar13,"error on line %ld of %s\n",local_4ac[0],local_53c);
  }
LAB_00424810:
  iVar18 = 0;
  iVar19 = 0;
LAB_004245d0:
  iVar36 = 0;
LAB_004245d8:
  piVar38 = (int *)0x0;
  piVar32 = (int *)0x0;
LAB_004245dc:
  uVar17 = 1;
  (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar13);
  do {
    if ((req_conf != 0) && (req_conf != *(int *)PTR_config_006a7f68)) {
      (*(code *)PTR_NCONF_free_006a7f6c)();
    }
    (*(code *)PTR_BIO_free_006a7f70)(iVar19);
    (*(code *)PTR_BIO_free_all_006a7f74)(iVar18);
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(local_4c4);
    if (iVar36 != 0) {
      (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(iVar36);
    }
    if (local_564 != (undefined4 *)0x0) {
      (*(code *)PTR_sk_free_006a7f80)(local_564);
    }
    if (local_558 != (undefined4 *)0x0) {
      (*(code *)PTR_sk_free_006a7f80)(local_558);
    }
    if (local_570 != 0) {
      (*(code *)PTR_ENGINE_free_006a7f84)(local_570);
    }
    if (local_4c8 != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    (*(code *)PTR_X509_REQ_free_006a7f8c)(piVar38);
    (*(code *)PTR_X509_free_006a7f90)(piVar32);
    (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(local_554);
    if ((local_560 != (char *)0x0) && (local_4b8 != 0)) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    if ((local_55c != (char *)0x0) && (local_4b4 != 0)) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    (*(code *)PTR_OBJ_cleanup_006a7f98)();
    if (local_2c == *(int *)puVar15) {
      return uVar17;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00425c50:
    (*(code *)PTR_ERR_clear_error_006a7fe0)();
LAB_004250b4:
    (*(code *)PTR_app_RAND_load_file_006a7fcc)(iVar36,*(undefined4 *)puVar13,0);
LAB_004250cc:
    if (local_538 != (char *)0x0) {
      if (local_4c4 == 0) {
        iVar20 = (*(code *)PTR_NCONF_get_string_006a7fa8)(req_conf,piVar32 + 0x919,"RANDFILE");
        if (iVar20 == 0) {
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
        }
        (*(code *)PTR_app_RAND_load_file_006a7fcc)(iVar20,*(undefined4 *)puVar13,0);
        if (local_4d4 != (char *)0x0) {
          (*(code *)PTR_app_RAND_load_files_006a8038)(local_4d4);
        }
        if (local_4e4 == (char *)0x0) {
          iVar36 = 0;
        }
        else {
          iVar36 = set_keygen_ctx(*(undefined4 *)puVar13,local_4e4,&local_4c0,&local_4bc,&local_4c8,
                                  local_570);
          if (iVar36 == 0) goto LAB_004245d8;
        }
        if ((local_4bc < 1) &&
           (iVar21 = (*(code *)PTR_NCONF_get_number_e_006a803c)
                               (req_conf,piVar32 + 0x919,"default_bits",&local_4bc), iVar21 == 0)) {
          local_4bc = 0x200;
        }
        else if ((local_4bc < 0x180) && ((local_4c0 == 6 || (local_4c0 == 0x74)))) {
          piVar38 = (int *)0x0;
          piVar32 = (int *)0x0;
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar13,"private key length is too short,\n");
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar13,"it needs to be at least %d bits, not %ld\n",0x180,
                     local_4bc);
          goto LAB_004245dc;
        }
        if ((iVar36 == 0) &&
           (iVar36 = set_keygen_ctx(*(undefined4 *)puVar13,0,&local_4c0,&local_4bc,&local_4c8,
                                    local_570), iVar36 == 0)) goto LAB_004245d8;
        iVar21 = 0;
        if (local_564 != (undefined4 *)0x0) {
          for (; iVar22 = (*(code *)PTR_sk_num_006a7f2c)(local_564), iVar21 < iVar22;
              iVar21 = iVar21 + 1) {
            uVar17 = (*(code *)PTR_sk_value_006a7f24)(local_564,iVar21);
            iVar22 = (*(code *)PTR_pkey_ctrl_string_006a7f28)(iVar36,uVar17);
            if (iVar22 < 1) {
              piVar38 = (int *)0x0;
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar13,"parameter error \"%s\"\n",uVar17);
              piVar32 = (int *)0x0;
              (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar13);
              goto LAB_004245dc;
            }
          }
        }
        puVar14 = PTR_bio_err_006a7f3c;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,"Generating a %ld bit %s private key\n",local_4bc,
                   local_4c8);
        (*(code *)PTR_EVP_PKEY_CTX_set_cb_006a8040)(iVar36,genpkey_cb);
        (*(code *)PTR_EVP_PKEY_CTX_set_app_data_006a8044)(iVar36,*(undefined4 *)puVar13);
        iVar21 = (*(code *)PTR_EVP_PKEY_keygen_006a8048)(iVar36,&local_4c4);
        if (iVar21 < 1) {
          piVar32 = (int *)0x0;
          piVar38 = (int *)0x0;
          (*(code *)PTR_BIO_puts_006a8058)(*(undefined4 *)puVar14,"Error Generating Key\n");
          goto LAB_004245dc;
        }
        (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(iVar36);
        (*(code *)PTR_app_RAND_write_file_006a804c)(iVar20,*(undefined4 *)puVar14);
        if ((local_51c == (char *)0x0) &&
           (local_51c = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                          (req_conf,piVar32 + 0x919,"default_keyfile"),
           local_51c == (char *)0x0)) {
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar14,"writing new private key to stdout\n");
          (*(code *)PTR_BIO_ctrl_006a7f18)(iVar18,0x6a,0,*(undefined4 *)PTR_stdout_006aaad4);
        }
        else {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar13,"writing new private key to \'%s\'\n",local_51c);
          iVar36 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar18,0x6c,5,local_51c);
          pcVar35 = local_51c;
          if (iVar36 < 1) goto LAB_00426268;
        }
        pcVar35 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                    (req_conf,piVar32 + 0x919,"encrypt_rsa_key");
        if (pcVar35 == (char *)0x0) {
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
          pcVar35 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                      (req_conf,piVar32 + 0x919,"encrypt_key");
          if (pcVar35 != (char *)0x0) goto LAB_00426170;
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
        }
        else {
LAB_00426170:
          if (((*pcVar35 == 'n') && (pcVar35[1] == 'o')) && (pcVar35[2] == '\0')) {
            local_508 = 0;
          }
        }
        iVar36 = 4;
        if (local_4dc != (char *)0x0) {
          local_508 = 0;
        }
        while (iVar20 = (*(code *)PTR_PEM_write_bio_PrivateKey_006a8050)
                                  (iVar18,local_4c4,local_508,0,0,0,local_4b4), iVar20 == 0) {
          uVar24 = (*(code *)PTR_ERR_peek_error_006a8054)();
          if (((uVar24 & 0xfff) != 0x6d) || (iVar36 = iVar36 + -1, iVar36 == 0)) goto LAB_004245d0;
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
        }
        piVar38 = (int *)0x0;
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"-----\n");
        if (local_4c4 == 0) {
LAB_00425644:
          iVar36 = 0;
          piVar32 = (int *)0x0;
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar13,"you need to specify a private key\n");
          goto LAB_004245dc;
        }
      }
      piVar38 = (int *)(*(code *)PTR_X509_REQ_new_006a7fd0)();
      iVar36 = local_4c4;
      if (piVar38 != (int *)0x0) {
        local_508 = local_4c4;
        pcVar35 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                    (req_conf,piVar32 + 0x919,"prompt");
        if (pcVar35 == (char *)0x0) {
          bVar2 = false;
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
        }
        else {
          bVar2 = *pcVar35 == 'n';
          if ((*pcVar35 == 'n') && (bVar2 = pcVar35[1] == 'o', pcVar35[1] == 'o')) {
            bVar2 = pcVar35[2] == '\0';
          }
        }
        iVar20 = (*(code *)PTR_NCONF_get_string_006a7fa8)
                           (req_conf,piVar32 + 0x919,"distinguished_name");
        pcVar35 = pcVar39;
        if (iVar20 == 0) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar13,"unable to find \'%s\' in config\n","distinguished_name"
                    );
        }
        else {
          iVar21 = (*(code *)PTR_NCONF_get_section_006a7fd4)(req_conf,iVar20);
          if (iVar21 == 0) {
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)puVar13,"unable to get \'%s\' section\n",iVar20);
          }
          else {
            iVar22 = (*(code *)PTR_NCONF_get_string_006a7fa8)(req_conf,piVar32 + 0x919,"attributes")
            ;
            if (iVar22 == 0) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
              local_53c = (char *)0x0;
            }
            else {
              local_53c = (char *)(*(code *)PTR_NCONF_get_section_006a7fd4)(req_conf,iVar22);
              if (local_53c == (char *)0x0) {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar13,"unable to get \'%s\' section\n",iVar22);
                goto LAB_00425224;
              }
            }
            iVar23 = (*(code *)PTR_X509_REQ_set_version_006a7fd8)(piVar38,0);
            if (iVar23 != 0) {
              if (bVar2) {
                uVar17 = *(undefined4 *)(*piVar38 + 0x10);
                for (iVar20 = 0; iVar22 = (*(code *)PTR_sk_num_006a7f2c)(iVar21), iVar20 < iVar22;
                    iVar20 = iVar20 + 1) {
                  iVar22 = (*(code *)PTR_sk_value_006a7f24)(iVar21,iVar20);
                  pbVar26 = *(byte **)(iVar22 + 4);
                  bVar30 = *pbVar26;
                  pbVar33 = pbVar26;
                  while (bVar30 != 0) {
                    if ((bVar30 == 0x3a) || ((bVar30 & 0xfd) == 0x2c)) {
                      bVar30 = pbVar33[1];
                      if (bVar30 != 0) {
                        pbVar26 = pbVar33 + 1;
                      }
                      break;
                    }
                    pbVar33 = pbVar33 + 1;
                    bVar30 = *pbVar33;
                  }
                  iVar22 = (*(code *)PTR_X509_NAME_add_entry_by_txt_006a8070)
                                     (uVar17,pbVar26,local_534,*(undefined4 *)(iVar22 + 8),
                                      0xffffffff,0xffffffff,-(uint)(bVar30 == 0x2b));
                  if (iVar22 == 0) goto LAB_00425224;
                }
                iVar20 = (*(code *)PTR_X509_NAME_entry_count_006a8074)(uVar17);
                if (iVar20 != 0) {
                  if (!bVar5) {
                    for (iVar20 = 0; iVar21 = (*(code *)PTR_sk_num_006a7f2c)(local_53c),
                        iVar20 < iVar21; iVar20 = iVar20 + 1) {
                      iVar21 = (*(code *)PTR_sk_value_006a7f24)(local_53c,iVar20);
                      iVar21 = (*(code *)PTR_X509_REQ_add1_attr_by_txt_006a8078)
                                         (piVar38,*(undefined4 *)(iVar21 + 4),local_534,
                                          *(undefined4 *)(iVar21 + 8),0xffffffff);
                      if (iVar21 == 0) goto LAB_00425224;
                    }
                  }
                  goto LAB_00425d70;
                }
LAB_00426a70:
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar13,"error, no objects specified in config file\n");
                pcVar35 = pcVar39;
              }
              else if (local_520 == (char *)0x0) {
                local_538 = *(char **)(*piVar38 + 0x10);
                if (batch == 0) {
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (*(undefined4 *)puVar13,
                             "You are about to be asked to enter information that will be incorporated\n"
                            );
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (*(undefined4 *)puVar13,"into your certificate request.\n");
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (*(undefined4 *)puVar13,
                             "What you are about to enter is what is called a Distinguished Name or a DN.\n"
                            );
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (*(undefined4 *)puVar13,
                             "There are quite a few fields but you can leave some blank\n");
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (*(undefined4 *)puVar13,
                             "For some fields there will be a default value,\n");
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (*(undefined4 *)puVar13,
                             "If you enter \'.\', the field will be left blank.\n");
                  (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"-----\n");
                }
                iVar23 = (*(code *)PTR_sk_num_006a7f2c)(iVar21);
                if (iVar23 != 0) {
                  local_520 = (char *)0xffffffff;
                  local_4e4 = "_max";
                  local_4dc = "%s [%s]:";
                  local_518 = "\n";
LAB_00426470:
                  local_520 = local_520 + 1;
                  iVar23 = (*(code *)PTR_sk_num_006a7f2c)(iVar21);
                  local_4d4 = pcVar39;
                  if ((int)local_520 < iVar23) {
                    iVar23 = (*(code *)PTR_sk_value_006a7f24)(iVar21,local_520);
                    pbVar33 = *(byte **)(iVar23 + 4);
                    iVar25 = check_end(pbVar33,&DAT_00633f14);
                    if ((((iVar25 != 0) && (iVar25 = check_end(pbVar33,&DAT_00633f1c), iVar25 != 0))
                        && (iVar25 = check_end(pbVar33,"_default"), iVar25 != 0)) &&
                       (iVar25 = check_end(pbVar33,"_value"), iVar25 != 0)) {
                      bVar30 = *pbVar33;
                      if (bVar30 == 0) {
LAB_00426580:
                        uVar17 = 0;
                      }
                      else if ((bVar30 == 0x3a) || (pbVar26 = pbVar33, (bVar30 & 0xfd) == 0x2c)) {
                        pbVar26 = pbVar33;
                        bVar1 = pbVar33[1];
                        if (pbVar33[1] != 0) goto LAB_0042656c;
                        uVar17 = 0;
                      }
                      else {
                        do {
                          pbVar3 = pbVar26;
                          pbVar26 = pbVar3 + 1;
                          bVar1 = *pbVar26;
                          if (bVar1 == 0) goto LAB_00426574;
                        } while ((bVar1 != 0x3a) && ((bVar1 & 0xfd) != 0x2c));
                        bVar1 = pbVar3[2];
                        if (bVar1 != 0) {
LAB_0042656c:
                          bVar30 = bVar1;
                          pbVar33 = pbVar26 + 1;
                        }
LAB_00426574:
                        if (bVar30 != 0x2b) goto LAB_00426580;
                        pbVar33 = pbVar33 + 1;
                        uVar17 = 0xffffffff;
                      }
                      iVar25 = (*(code *)PTR_OBJ_txt2nid_006a805c)(pbVar33);
                      if (iVar25 != 0) {
                        iVar27 = (*(code *)PTR_BIO_snprintf_006a8060)
                                           (auStack_490,100,"%s_default",*(undefined4 *)(iVar23 + 4)
                                           );
                        if (99 < iVar27) {
                          uVar17 = *(undefined4 *)(iVar23 + 4);
                          goto LAB_00426944;
                        }
                        pcVar28 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                                    (req_conf,iVar20,auStack_490);
                        if (pcVar28 == (char *)0x0) {
                          pcVar28 = "";
                          (*(code *)PTR_ERR_clear_error_006a7fe0)();
                        }
                        (*(code *)PTR_BIO_snprintf_006a8060)
                                  (auStack_490,100,"%s_value",*(undefined4 *)(iVar23 + 4));
                        pcVar35 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                                    (req_conf,iVar20,auStack_490);
                        if (pcVar35 == (char *)0x0) {
                          (*(code *)PTR_ERR_clear_error_006a7fe0)();
                        }
                        (*(code *)PTR_BIO_snprintf_006a8060)
                                  (auStack_490,100,"%s_min",*(undefined4 *)(iVar23 + 4));
                        iVar27 = (*(code *)PTR_NCONF_get_number_e_006a803c)
                                           (req_conf,iVar20,auStack_490,&local_4b0);
                        if (iVar27 == 0) {
                          (*(code *)PTR_ERR_clear_error_006a7fe0)();
                          local_4b0 = (char *)0xffffffff;
                        }
                        (*(code *)PTR_BIO_snprintf_006a8060)
                                  (auStack_490,100,"%s_max",*(undefined4 *)(iVar23 + 4));
                        iVar27 = (*(code *)PTR_NCONF_get_number_e_006a803c)
                                           (req_conf,iVar20,auStack_490,local_4ac);
                        if (iVar27 == 0) {
                          (*(code *)PTR_ERR_clear_error_006a7fe0)();
                          local_4ac[0] = 0xffffffff;
                        }
                        uVar41 = local_4ac[0];
                        pcVar16 = local_4b0;
                        uVar37 = *(undefined4 *)(iVar23 + 8);
                        local_4fc = 0x630000;
                        local_500 = local_4b0;
                        do {
                          if (batch == 0) {
                            (*(code *)PTR_BIO_printf_006a7f38)
                                      (*(undefined4 *)puVar13,"%s [%s]:",uVar37,pcVar28);
                          }
                          (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar13,0xb,0,0);
                          if (pcVar35 == (char *)0x0) {
                            acStack_42d[1] = '\0';
                            if (batch == 0) {
                              iVar23 = (*(code *)PTR_fgets_006aabe8)
                                                 (acStack_42d + 1,0x400,
                                                  *(undefined4 *)PTR_stdin_006aab20);
                              if (iVar23 != 0) goto LAB_004267ac;
                              goto LAB_00425224;
                            }
                            acStack_42d[2] = '\0';
                            acStack_42d[1] = '\n';
LAB_00426a1c:
                            if (*pcVar28 == '\0') goto LAB_00426470;
                            (*(code *)PTR_BUF_strlcpy_006a8064)(acStack_42d + 1,pcVar28,0x400);
                            (*(code *)PTR_BUF_strlcat_006a8068)(acStack_42d + 1,"\n",0x400);
                          }
                          else {
                            (*(code *)PTR_BUF_strlcpy_006a8064)(acStack_42d + 1,pcVar35,0x400);
                            (*(code *)PTR_BUF_strlcat_006a8068)(acStack_42d + 1,"\n",0x400);
                            (*(code *)PTR_BIO_printf_006a7f38)
                                      (*(undefined4 *)PTR_bio_err_006a7f3c,"%s\n",pcVar35);
LAB_004267ac:
                            if (acStack_42d[1] == '\0') goto LAB_00425224;
                            if (acStack_42d[1] == '\n') goto LAB_00426a1c;
                            if ((acStack_42d[1] == '.') && (acStack_42d[2] == '\n'))
                            goto LAB_00426470;
                          }
                          iVar23 = (*(code *)PTR_strlen_006aab30)(acStack_42d + 1);
                          if (acStack_42d[iVar23] != '\n') goto LAB_00426a94;
                          acStack_42d[iVar23] = '\0';
                          iVar23 = req_check_len(iVar23 + -1,pcVar16,uVar41);
                        } while (iVar23 == 0);
                        iVar23 = (*(code *)PTR_X509_NAME_add_entry_by_NID_006a806c)
                                           (local_538,iVar25,local_534,acStack_42d + 1,0xffffffff,
                                            0xffffffff,uVar17);
                        if (iVar23 == 0) goto LAB_00425224;
                      }
                    }
                    goto LAB_00426470;
                  }
                  iVar20 = (*(code *)PTR_X509_NAME_entry_count_006a8074)(local_538);
                  if (iVar20 == 0) goto LAB_00426a70;
                  if ((!bVar5) && (local_53c != (char *)0x0)) {
                    iVar20 = (*(code *)PTR_sk_num_006a7f2c)(local_53c);
                    if ((0 < iVar20) && (batch == 0)) {
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (*(undefined4 *)puVar13,
                                 "\nPlease enter the following \'extra\' attributes\n");
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (*(undefined4 *)puVar13,"to be sent with your certificate request\n"
                                );
                    }
                    local_54c = 0;
                    local_500 = (char *)0x630000;
                    local_538 = "\n";
                    local_4e4 = "%s\n";
LAB_00426ba4:
                    local_4fc = 0x630000;
                    iVar20 = (*(code *)PTR_sk_num_006a7f2c)(local_53c);
                    if (local_54c < iVar20) {
                      iVar20 = (*(code *)PTR_sk_value_006a7f24)(local_53c,local_54c);
                      uVar17 = *(undefined4 *)(iVar20 + 4);
                      pcVar35 = (char *)(*(code *)PTR_OBJ_txt2nid_006a805c)(uVar17);
                      if (pcVar35 == (char *)0x0) goto LAB_00426bfc;
                      iVar21 = (*(code *)PTR_BIO_snprintf_006a8060)
                                         (auStack_490,100,"%s_default",uVar17);
                      if (iVar21 < 100) {
                        pcVar28 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                                    (req_conf,iVar22,auStack_490);
                        if (pcVar28 == (char *)0x0) {
                          pcVar28 = "";
                          (*(code *)PTR_ERR_clear_error_006a7fe0)();
                        }
                        (*(code *)PTR_BIO_snprintf_006a8060)(auStack_490,100,"%s_value",uVar17);
                        iVar21 = (*(code *)PTR_NCONF_get_string_006a7fa8)
                                           (req_conf,iVar22,auStack_490);
                        if (iVar21 == 0) {
                          (*(code *)PTR_ERR_clear_error_006a7fe0)();
                        }
                        (*(code *)PTR_BIO_snprintf_006a8060)(auStack_490,100,"%s_min",uVar17);
                        iVar23 = (*(code *)PTR_NCONF_get_number_e_006a803c)
                                           (req_conf,iVar22,auStack_490,&local_4b0);
                        if (iVar23 == 0) {
                          (*(code *)PTR_ERR_clear_error_006a7fe0)();
                          local_4b0 = (char *)0xffffffff;
                        }
                        (*(code *)PTR_BIO_snprintf_006a8060)(auStack_490,100,"%s_max",uVar17);
                        iVar23 = (*(code *)PTR_NCONF_get_number_e_006a803c)
                                           (req_conf,iVar22,auStack_490,local_4ac);
                        if (iVar23 == 0) {
                          (*(code *)PTR_ERR_clear_error_006a7fe0)();
                          local_4ac[0] = 0xffffffff;
                        }
                        uVar17 = local_4ac[0];
                        pcVar16 = local_4b0;
                        puVar14 = PTR_bio_err_006a7f3c;
                        uVar41 = *(undefined4 *)(iVar20 + 8);
                        local_520 = local_4b0;
                        local_518 = PTR_bio_err_006a7f3c;
                        do {
                          if (batch == 0) {
                            (*(code *)PTR_BIO_printf_006a7f38)
                                      (*(undefined4 *)puVar13,"%s [%s]:",uVar41,pcVar28);
                          }
                          (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar13,0xb,0,0);
                          if (iVar21 == 0) {
                            buf_16713[0] = '\0';
                            if (batch == 0) {
                              iVar20 = (*(code *)PTR_fgets_006aabe8)
                                                 (buf_16713,0x400,*(undefined4 *)PTR_stdin_006aab20)
                              ;
                              if (iVar20 != 0) goto LAB_00426e38;
                              goto LAB_00426fac;
                            }
                            buf_16713[0] = '\n';
                            buf_16713[1] = '\0';
LAB_00426f4c:
                            if (*pcVar28 == '\0') goto LAB_00426bfc;
                            (*(code *)PTR_BUF_strlcpy_006a8064)(buf_16713,pcVar28,0x400);
                            (*(code *)PTR_BUF_strlcat_006a8068)(buf_16713,"\n",0x400);
                          }
                          else {
                            (*(code *)PTR_BUF_strlcpy_006a8064)(buf_16713,iVar21,0x400);
                            (*(code *)PTR_BUF_strlcat_006a8068)(buf_16713,"\n",0x400);
                            (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar14,"%s\n",iVar21)
                            ;
LAB_00426e38:
                            if (buf_16713[0] == '\0') {
LAB_00426fac:
                              local_4fc = 0x630000;
                              goto LAB_00425224;
                            }
                            if (buf_16713[0] == '\n') goto LAB_00426f4c;
                            if ((buf_16713[0] == '.') && (buf_16713[1] == '\n')) goto LAB_00426bfc;
                          }
                          local_4fc = 0x630000;
                          iVar20 = (*(code *)PTR_strlen_006aab30)(buf_16713);
                          if ((&DAT_006aad1f)[iVar20] != '\n') goto LAB_00426a94;
                          (&DAT_006aad1f)[iVar20] = '\0';
                          iVar20 = req_check_len(iVar20 + -1,pcVar16,uVar17);
                        } while (iVar20 == 0);
                        iVar20 = (*(code *)PTR_X509_REQ_add1_attr_by_NID_006a807c)
                                           (piVar38,pcVar35,local_534,buf_16713,0xffffffff);
                        if (iVar20 != 0) goto LAB_00426bfc;
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*(undefined4 *)puVar13,"Error adding attribute\n");
                        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar13);
                      }
                      else {
                        uVar17 = *(undefined4 *)(iVar20 + 4);
LAB_00426944:
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*(undefined4 *)puVar13,"Name \'%s\' too long\n",uVar17);
                      }
                      goto LAB_00425224;
                    }
                  }
                  goto LAB_00425d70;
                }
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar13,"No template, please set one up.\n");
              }
              else {
                iVar20 = build_subject(piVar38,local_520,local_534);
                if (iVar20 != 0) {
LAB_00425d70:
                  iVar36 = (*(code *)PTR_X509_REQ_set_pubkey_006a8030)(piVar38,iVar36);
                  pcVar35 = pcVar39;
                  if (iVar36 != 0) {
                    if ((bVar4) &&
                       (iVar36 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(*piVar38 + 0x18)),
                       iVar36 == 0)) {
                      (*(code *)PTR_sk_free_006a7f80)(*(undefined4 *)(*piVar38 + 0x18));
                      *(undefined4 *)(*piVar38 + 0x18) = 0;
                    }
                    if (bVar5) {
                      local_520 = (char *)0x0;
                      goto LAB_004255dc;
                    }
                    (*(code *)PTR_X509V3_set_ctx_006a7fb4)(local_4ac,0,0,piVar38,0,0);
                    (*(code *)PTR_X509V3_set_nconf_006a7fb8)(local_4ac,req_conf);
                    if ((local_528 == (char *)0x0) ||
                       (iVar36 = (*(code *)PTR_X509V3_EXT_REQ_add_nconf_006a8034)
                                           (req_conf,local_4ac,local_528,piVar38), iVar36 != 0)) {
                      iVar36 = do_X509_REQ_sign(*(undefined4 *)puVar13,piVar38,local_4c4,local_504,
                                                local_558);
                      if (iVar36 != 0) goto LAB_00425698;
                      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
                    }
                    else {
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (*(undefined4 *)puVar13,"Error Loading extension section %s\n",
                                 local_528);
                    }
                    goto LAB_00425e70;
                  }
                }
              }
            }
          }
        }
        goto LAB_00425224;
      }
LAB_00425e70:
      iVar36 = 0;
      piVar32 = (int *)0x0;
      goto LAB_004245dc;
    }
    if (local_500 == (char *)0x0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar19,0x6a,0,*(undefined4 *)PTR_stdin_006aab20);
    }
    else {
      iVar36 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar19,0x6c,3,local_500);
      pcVar35 = local_500;
      if (iVar36 < 1) {
LAB_00426268:
        iVar36 = 0;
        (*(code *)PTR_perror_006aab88)(pcVar35);
        piVar38 = (int *)0x0;
        piVar32 = (int *)0x0;
        goto LAB_004245dc;
      }
    }
    if (piVar38 == (int *)0x1) {
      piVar38 = (int *)(*(code *)PTR_d2i_X509_REQ_bio_006a8080)(iVar19,0);
    }
    else {
      if (piVar38 != (int *)0x3) {
        iVar36 = 0;
        piVar38 = (int *)0x0;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,"bad input format specified for X509 request\n");
        piVar32 = (int *)0x0;
        goto LAB_004245dc;
      }
      piVar38 = (int *)(*(code *)PTR_PEM_read_bio_X509_REQ_006a7fe4)(iVar19,0,0,0);
    }
    if (piVar38 == (int *)0x0) {
      iVar36 = 0;
      piVar32 = (int *)0x0;
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"unable to load X509 request\n");
      goto LAB_004245dc;
    }
    if (bVar5) {
      if (local_4c4 == 0) goto LAB_00425644;
LAB_004255dc:
      piVar32 = (int *)(*(code *)PTR_X509_new_006a7fe8)();
      if ((piVar32 != (int *)0x0) &&
         ((local_52c == (char *)0x0 ||
          (iVar36 = (*(code *)PTR_X509_set_version_006a7fec)(piVar32,2), iVar36 != 0)))) {
        if (local_554 == 0) {
          uVar17 = (*(code *)PTR_X509_get_serialNumber_006a809c)(piVar32);
          iVar36 = (*(code *)PTR_rand_serial_006a80a0)(0,uVar17);
          if (iVar36 != 0) {
            iVar36 = *piVar38;
            goto LAB_0042717c;
          }
        }
        else {
          iVar36 = (*(code *)PTR_X509_set_serialNumber_006a8084)(piVar32,local_554);
          if (iVar36 != 0) {
            iVar36 = *piVar38;
LAB_0042717c:
            iVar36 = (*(code *)PTR_X509_set_issuer_name_006a8088)
                               (piVar32,*(undefined4 *)(iVar36 + 0x10));
            if ((((iVar36 != 0) &&
                 (iVar36 = (*(code *)PTR_X509_gmtime_adj_006a808c)
                                     (**(undefined4 **)(*piVar32 + 0x10),0), iVar36 != 0)) &&
                (iVar36 = (*(code *)PTR_X509_time_adj_ex_006a8090)
                                    (*(undefined4 *)(*(int *)(*piVar32 + 0x10) + 4),local_4e8,0,0),
                iVar36 != 0)) &&
               (((iVar36 = (*(code *)PTR_X509_set_subject_name_006a8094)
                                     (piVar32,*(undefined4 *)(*piVar38 + 0x10)), iVar36 != 0 &&
                 (iVar36 = (*(code *)PTR_X509_REQ_get_pubkey_006a7ff4)(piVar38), iVar36 != 0)) &&
                (iVar20 = (*(code *)PTR_X509_set_pubkey_006a8098)(piVar32,iVar36), iVar20 != 0)))) {
              (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar36);
              (*(code *)PTR_X509V3_set_ctx_006a7fb4)(local_4ac,piVar32,piVar32,0,0,0);
              (*(code *)PTR_X509V3_set_nconf_006a7fb8)(local_4ac,req_conf);
              if ((local_52c == (char *)0x0) ||
                 (iVar36 = (*(code *)PTR_X509V3_EXT_add_nconf_006a7fbc)
                                     (req_conf,local_4ac,local_52c,piVar32), iVar36 != 0)) {
                puVar14 = PTR_bio_err_006a7f3c;
                iVar36 = do_X509_sign(*(undefined4 *)puVar13,piVar32,local_4c4,local_504,local_558);
                if (iVar36 != 0) {
                  if (local_520 == (char *)0x0) goto LAB_004256f4;
                  iVar36 = 0;
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (*(undefined4 *)puVar14,"Cannot modifiy certificate subject\n");
                  goto LAB_004245dc;
                }
                (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar14);
              }
              else {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar13,"Error Loading extension section %s\n",local_52c);
              }
            }
          }
        }
      }
LAB_00425614:
      iVar36 = 0;
      goto LAB_004245dc;
    }
    if (local_520 != (char *)0x0) {
      if (local_518 == (char *)0x0) {
        iVar36 = build_subject(piVar38,local_520,local_534);
        if (iVar36 == 0) {
LAB_00426fcc:
          iVar36 = 0;
          piVar32 = (int *)0x0;
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar13,"ERROR: cannot modify subject\n");
          goto LAB_004245dc;
        }
        *(undefined4 *)(*piVar38 + 8) = 1;
      }
      else {
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"Modifying Request\'s Subject\n");
        (*(code *)PTR_print_name_006a8004)
                  (*(undefined4 *)puVar13,"old subject=",*(undefined4 *)(*piVar38 + 0x10),local_4d0)
        ;
        iVar36 = build_subject(piVar38,local_520,local_534,local_4fc);
        puVar14 = PTR_print_name_006a8004;
        if (iVar36 == 0) goto LAB_00426fcc;
        iVar36 = *piVar38;
        uVar17 = *(undefined4 *)PTR_bio_err_006a7f3c;
        *(undefined4 *)(iVar36 + 8) = 1;
        (*(code *)puVar14)(uVar17,"new subject=",*(undefined4 *)(iVar36 + 0x10),local_4d0);
      }
    }
LAB_00425698:
    piVar32 = (int *)0x0;
    if (bVar6) {
      if (local_4c4 == 0) {
        local_4c4 = (*(code *)PTR_X509_REQ_get_pubkey_006a7ff4)(piVar38);
        if (local_4c4 == 0) goto LAB_00425e70;
        iVar36 = (*(code *)PTR_X509_REQ_verify_006a7ff0)(piVar38,local_4c4);
        (*(code *)PTR_EVP_PKEY_free_006a7f78)(local_4c4);
        local_4c4 = 0;
      }
      else {
        iVar36 = (*(code *)PTR_X509_REQ_verify_006a7ff0)(piVar38);
      }
      if (iVar36 < 0) goto LAB_00425e70;
      if (iVar36 == 0) {
        piVar32 = (int *)0x0;
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"verify failure\n");
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar13);
      }
      else {
        piVar32 = (int *)0x0;
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"verify OK\n");
      }
    }
LAB_004256f4:
    if ((((!bVar7) || (bVar8)) || (bVar9)) || ((bVar10 || (bVar11)))) {
      if (local_514 == (char *)0x0) {
        (*(code *)PTR_BIO_ctrl_006a7f18)(iVar18,0x6a,0,*(undefined4 *)PTR_stdout_006aaad4);
      }
      else {
        if ((local_51c == (char *)0x0) ||
           (iVar36 = (*(code *)PTR_strcmp_006aac20)(local_514,local_51c), iVar36 != 0)) {
          uVar17 = 5;
        }
        else {
          uVar17 = 9;
        }
        iVar36 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar18,0x6c,uVar17,local_514);
        if (iVar36 == 0) {
          iVar36 = 0;
          (*(code *)PTR_perror_006aab88)(local_514);
          goto LAB_004245dc;
        }
      }
      if (bVar11) {
        iVar36 = (*(code *)PTR_X509_REQ_get_pubkey_006a7ff4)(piVar38);
        if (iVar36 == 0) {
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"Error getting public key\n");
          (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar13);
          goto LAB_004245dc;
        }
        (*(code *)PTR_PEM_write_bio_PUBKEY_006a8028)(iVar18,iVar36);
        (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar36);
      }
      if (bVar8) {
        if (bVar5) {
          (*(code *)PTR_X509_print_ex_006a7ffc)(iVar18,piVar32,local_4d0,local_4cc);
          if (bVar10) goto LAB_004257c4;
          if (!bVar9) goto LAB_00425894;
LAB_004257fc:
          iVar36 = (*(code *)PTR_X509_get_pubkey_006a8008)(piVar32);
        }
        else {
          (*(code *)PTR_X509_REQ_print_ex_006a7ff8)(iVar18,piVar38,local_4d0,local_4cc);
          if (bVar10) {
LAB_00425a44:
            (*(code *)PTR_print_name_006a8004)
                      (iVar18,"subject=",*(undefined4 *)(*piVar38 + 0x10),local_4d0);
          }
          if (!bVar9) goto LAB_00425894;
LAB_00425a74:
          iVar36 = (*(code *)PTR_X509_REQ_get_pubkey_006a7ff4)(piVar38);
        }
        puVar14 = PTR_stdout_006aaad4;
        if (iVar36 == 0) {
          (*(code *)PTR_fwrite_006aab7c)
                    ("Modulus=unavailable\n",1,0x14,*(undefined4 *)PTR_stdout_006aaad4);
          goto LAB_004245dc;
        }
        (*(code *)PTR_fwrite_006aab7c)("Modulus=",1,8,*(undefined4 *)PTR_stdout_006aaad4);
        iVar20 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(iVar36);
        if (iVar20 == 6) {
          (*(code *)PTR_BN_print_006a8024)(iVar18,*(undefined4 *)(*(int *)(iVar36 + 0x14) + 0x10));
        }
        else {
          (*(code *)PTR_fwrite_006aab7c)("Wrong Algorithm type",1,0x14,*(undefined4 *)puVar14);
        }
        (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar36);
        (*(code *)PTR_fputc_006aaab0)(10,*(undefined4 *)puVar14);
      }
      else if (bVar10) {
        if (!bVar5) goto LAB_00425a44;
LAB_004257c4:
        uVar17 = (*(code *)PTR_X509_get_subject_name_006a8000)(piVar32);
        (*(code *)PTR_print_name_006a8004)(iVar18,"subject=",uVar17,local_4d0);
        if (bVar9) goto LAB_004257fc;
      }
      else if (bVar9) {
        if (bVar5) goto LAB_004257fc;
        goto LAB_00425a74;
      }
LAB_00425894:
      if (!bVar7) {
        if (bVar5) {
          if (piVar32 != (int *)0x0) {
            if (pcVar39 == (char *)0x1) {
              iVar36 = (*(code *)PTR_i2d_X509_bio_006a801c)(iVar18,piVar32);
            }
            else {
              if (pcVar39 != (char *)0x3) goto LAB_0042591c;
              iVar36 = (*(code *)PTR_PEM_write_bio_X509_006a8020)(iVar18,piVar32);
            }
            if (iVar36 == 0) {
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar13,"unable to write X509 certificate\n");
              goto LAB_00425614;
            }
          }
        }
        else {
          if (pcVar39 == (char *)0x1) {
            iVar36 = (*(code *)PTR_i2d_X509_REQ_bio_006a8010)(iVar18,piVar38);
          }
          else {
            if (pcVar39 != (char *)0x3) {
LAB_0042591c:
              iVar36 = 0;
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar13,"bad output format specified for outfile\n");
              goto LAB_004245dc;
            }
            if (bVar12) {
              iVar36 = (*(code *)PTR_PEM_write_bio_X509_REQ_NEW_006a8018)(iVar18,piVar38);
            }
            else {
              iVar36 = (*(code *)PTR_PEM_write_bio_X509_REQ_006a8014)(iVar18,piVar38);
            }
          }
          if (iVar36 == 0) goto LAB_004258ec;
        }
      }
    }
    iVar36 = 0;
    uVar17 = 0;
  } while( true );
LAB_00426a94:
  local_4fc = 0x630000;
  (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"weird input :-(\n");
LAB_00425224:
  if ((bVar4) &&
     (iVar36 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(*piVar38 + 0x18)), iVar36 == 0)) {
    (*(code *)PTR_sk_free_006a7f80)(*(undefined4 *)(*piVar38 + 0x18));
    *(undefined4 *)(*piVar38 + 0x18) = 0;
  }
  iVar36 = 0;
  piVar32 = (int *)0x0;
  (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"problems making Certificate Request\n")
  ;
  pcVar39 = pcVar35;
  goto LAB_004245dc;
LAB_00426bfc:
  local_54c = local_54c + 1;
  goto LAB_00426ba4;
LAB_004258ec:
  iVar36 = 0;
  (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"unable to write X509 request\n");
  goto LAB_004245dc;
}

