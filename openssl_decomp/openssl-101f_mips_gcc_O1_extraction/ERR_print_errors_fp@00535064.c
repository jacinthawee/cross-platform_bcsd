
void ERR_print_errors_fp(char **param_1)

{
  undefined4 uVar1;
  BIO_METHOD *type;
  ulong uVar2;
  int iVar3;
  BIO *pBVar4;
  BIO *a;
  char *unaff_s0;
  char *unaff_s1;
  int *unaff_s2;
  int *unaff_s3;
  char **unaff_s4;
  int *unaff_s5;
  char **unaff_s6;
  int *line;
  char *unaff_s7;
  undefined *puVar5;
  undefined *puVar6;
  BIO *file;
  char **unaff_s8;
  code *pcVar7;
  code *unaff_retaddr;
  undefined auStackX_0 [16];
  
  do {
    *(char **)((int)register0x00000074 + -0x28) = unaff_s0;
    a = (BIO *)((int)register0x00000074 + -0x1174);
    *(code **)((int)register0x00000074 + -4) = unaff_retaddr;
    *(char ***)((int)register0x00000074 + -8) = unaff_s8;
    file = (BIO *)((int)register0x00000074 + -0x1184);
    *(char **)((int)register0x00000074 + -0xc) = unaff_s7;
    line = (int *)((int)register0x00000074 + -0x117c);
    *(undefined **)((int)register0x00000074 + -0x118c) = PTR___stack_chk_guard_006aabf0;
    *(char ***)((int)register0x00000074 + -0x10) = unaff_s6;
    *(int **)((int)register0x00000074 + -0x14) = unaff_s5;
    *(char ***)((int)register0x00000074 + -0x18) = unaff_s4;
    *(int **)((int)register0x00000074 + -0x1c) = unaff_s3;
    *(int **)((int)register0x00000074 + -0x20) = unaff_s2;
    *(undefined **)((int)register0x00000074 + -0x11a0) = &_gp;
    *(char **)((int)register0x00000074 + -0x24) = unaff_s1;
    *(undefined4 *)((int)register0x00000074 + -0x2c) = *(undefined4 *)PTR___stack_chk_guard_006aabf0
    ;
    (*(code *)PTR_CRYPTO_THREADID_current_006a95ac)(a);
    uVar1 = (**(code **)(*(int *)((int)register0x00000074 + -0x11a0) + -0x693c))(a);
    *(undefined4 *)((int)register0x00000074 + -0x1194) = uVar1;
    *(char **)((int)register0x00000074 + -0x1190) = "s\n";
    do {
      pBVar4 = file;
      unaff_s2 = line;
      uVar2 = ERR_get_error_line_data
                        ((char **)file,line,(char **)((int)register0x00000074 + -0x1180),
                         (int *)((int)register0x00000074 + -0x1178));
      puVar5 = *(undefined **)((int)register0x00000074 + -0x11a0);
      if (uVar2 == 0) break;
      ERR_error_string_n(uVar2,(char *)((int)register0x00000074 + -0x112c),0x100);
      if ((*(uint *)((int)register0x00000074 + -0x1178) & 2) == 0) {
        iVar3 = *(int *)((int)register0x00000074 + -0x1190) + -0x6a30;
      }
      else {
        iVar3 = *(int *)((int)register0x00000074 + -0x1180);
      }
      unaff_s1 = (char *)((int)register0x00000074 + -0x102c);
      *(undefined4 *)((int)register0x00000074 + -0x11a8) =
           *(undefined4 *)((int)register0x00000074 + -0x117c);
      *(undefined4 *)((int)register0x00000074 + -0x11ac) =
           *(undefined4 *)((int)register0x00000074 + -0x1184);
      *(char **)((int)register0x00000074 + -0x11b0) = (char *)((int)register0x00000074 + -0x112c);
      a = (BIO *)((int)register0x00000074 + -0x116c);
      *(int *)((int)register0x00000074 + -0x11a4) = iVar3;
      BIO_snprintf(unaff_s1,0x1000,"%lu:%s:%s:%d:%s\n",
                   *(undefined4 *)((int)register0x00000074 + -0x1194));
      type = BIO_s_file();
      BIO_set(a,type);
      BIO_ctrl(a,0x6a,0,param_1);
      pBVar4 = a;
      unaff_s2 = (int *)0x6716dc;
      iVar3 = BIO_printf(a,"%s",unaff_s1);
      puVar5 = *(undefined **)((int)register0x00000074 + -0x11a0);
    } while (0 < iVar3);
    if (*(int *)((int)register0x00000074 + -0x2c) == **(int **)((int)register0x00000074 + -0x118c))
    {
      return;
    }
    pcVar7 = ERR_print_errors_cb;
    (**(code **)(puVar5 + -0x5328))();
    *(BIO **)((int)register0x00000074 + -0x11e8) = a;
    *(code **)((int)register0x00000074 + -0x11c4) = pcVar7;
    *(BIO **)((int)register0x00000074 + -0x11c8) = file;
    unaff_s8 = (char **)((int)register0x00000074 + -0x2304);
    *(int **)((int)register0x00000074 + -0x11cc) = line;
    unaff_s7 = (char *)((int)register0x00000074 + -0x22ec);
    *(undefined **)((int)register0x00000074 + -0x230c) = PTR___stack_chk_guard_006aabf0;
    *(char ***)((int)register0x00000074 + -0x11d0) = (char **)((int)register0x00000074 + -0x1180);
    unaff_s6 = (char **)((int)register0x00000074 + -0x21ec);
    *(char ***)((int)register0x00000074 + -0x11d4) = param_1;
    unaff_s5 = (int *)((int)register0x00000074 + -0x22fc);
    *(int **)((int)register0x00000074 + -0x11d8) = (int *)((int)register0x00000074 + -0x1178);
    unaff_s4 = (char **)((int)register0x00000074 + -0x2300);
    *(char **)((int)register0x00000074 + -0x11dc) = "%lu:%s:%s:%d:%s\n";
    unaff_s3 = (int *)((int)register0x00000074 + -0x22f8);
    *(char **)((int)register0x00000074 + -0x11e0) = "%s";
    *(char **)((int)register0x00000074 + -0x11e4) = unaff_s1;
    *(undefined **)((int)register0x00000074 + -0x2320) = &_gp;
    *(BIO **)((int)register0x00000074 + -0x2314) = pBVar4;
    *(undefined4 *)((int)register0x00000074 + -0x11ec) =
         *(undefined4 *)PTR___stack_chk_guard_006aabf0;
    (*(code *)PTR_CRYPTO_THREADID_current_006a95ac)
              ((undefined *)((int)register0x00000074 + -0x22f4));
    unaff_s0 = "%lu:%s:%s:%d:%s\n";
    unaff_s1 = (char *)(**(code **)(*(int *)((int)register0x00000074 + -0x2320) + -0x693c))
                                 ((undefined *)((int)register0x00000074 + -0x22f4));
    *(char **)((int)register0x00000074 + -0x2310) = "s\n";
    do {
      param_1 = unaff_s8;
      uVar2 = ERR_get_error_line_data(unaff_s8,unaff_s5,unaff_s4,unaff_s3);
      puVar6 = *(undefined **)((int)register0x00000074 + -0x2320);
      if (uVar2 == 0) break;
      ERR_error_string_n(uVar2,unaff_s7,0x100);
      if ((*(uint *)((int)register0x00000074 + -0x22f8) & 2) == 0) {
        iVar3 = *(int *)((int)register0x00000074 + -0x2310) + -0x6a30;
      }
      else {
        iVar3 = *(int *)((int)register0x00000074 + -0x2300);
      }
      *(undefined4 *)((int)register0x00000074 + -0x232c) =
           *(undefined4 *)((int)register0x00000074 + -0x2304);
      *(undefined4 *)((int)register0x00000074 + -9000) =
           *(undefined4 *)((int)register0x00000074 + -0x22fc);
      *(int *)((int)register0x00000074 + -0x2324) = iVar3;
      *(char **)((int)register0x00000074 + -0x2330) = unaff_s7;
      BIO_snprintf((char *)unaff_s6,0x1000,"%lu:%s:%s:%d:%s\n",unaff_s1);
      uVar1 = (**(code **)(*(int *)((int)register0x00000074 + -0x2320) + -0x53b0))(unaff_s6);
      param_1 = unaff_s6;
      iVar3 = (**(code **)((int)register0x00000074 + -0x2314))(unaff_s6,uVar1,unaff_s2);
      puVar6 = *(undefined **)((int)register0x00000074 + -0x2320);
    } while (0 < iVar3);
    if (*(int *)((int)register0x00000074 + -0x11ec) == **(int **)((int)register0x00000074 + -0x230c)
       ) {
      return;
    }
    unaff_retaddr = ERR_print_errors_fp;
    (**(code **)(puVar6 + -0x5328))();
    register0x00000074 = (BADSPACEBASE *)((int)register0x00000074 + -0x2340);
  } while( true );
}

