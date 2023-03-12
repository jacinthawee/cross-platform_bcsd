
void ERR_print_errors_cb(cb *cb,void *u)

{
  BIO_METHOD *type;
  undefined4 uVar1;
  ulong uVar2;
  int iVar3;
  BIO *unaff_s0;
  char *unaff_s1;
  int *unaff_s2;
  char *unaff_s3;
  int *unaff_s4;
  char **unaff_s5;
  char **unaff_s6;
  char **buf;
  int *unaff_s7;
  char *buf_00;
  undefined *puVar4;
  undefined *puVar5;
  BIO *unaff_s8;
  char **file;
  code *unaff_retaddr;
  code *pcVar6;
  undefined auStackX_0 [16];
  
  do {
    *(BIO **)((int)register0x00000074 + -0x28) = unaff_s0;
    *(code **)((int)register0x00000074 + -4) = unaff_retaddr;
    *(BIO **)((int)register0x00000074 + -8) = unaff_s8;
    file = (char **)((int)register0x00000074 + -0x1144);
    *(int **)((int)register0x00000074 + -0xc) = unaff_s7;
    buf_00 = (char *)((int)register0x00000074 + -0x112c);
    *(undefined **)((int)register0x00000074 + -0x114c) = PTR___stack_chk_guard_006aabf0;
    *(char ***)((int)register0x00000074 + -0x10) = unaff_s6;
    buf = (char **)((int)register0x00000074 + -0x102c);
    *(char ***)((int)register0x00000074 + -0x14) = unaff_s5;
    *(int **)((int)register0x00000074 + -0x18) = unaff_s4;
    *(char **)((int)register0x00000074 + -0x1c) = unaff_s3;
    *(int **)((int)register0x00000074 + -0x20) = unaff_s2;
    *(char **)((int)register0x00000074 + -0x24) = unaff_s1;
    *(undefined **)((int)register0x00000074 + -0x1160) = &_gp;
    *(cb **)((int)register0x00000074 + -0x1154) = cb;
    *(undefined4 *)((int)register0x00000074 + -0x2c) = *(undefined4 *)PTR___stack_chk_guard_006aabf0
    ;
    (*(code *)PTR_CRYPTO_THREADID_current_006a95ac)
              ((undefined *)((int)register0x00000074 + -0x1134));
    unaff_s1 = (char *)(**(code **)(*(int *)((int)register0x00000074 + -0x1160) + -0x693c))
                                 ((undefined *)((int)register0x00000074 + -0x1134));
    *(char **)((int)register0x00000074 + -0x1150) = "s\n";
    do {
      unaff_s5 = file;
      uVar2 = ERR_get_error_line_data
                        (file,(int *)((int)register0x00000074 + -0x113c),
                         (char **)((int)register0x00000074 + -0x1140),
                         (int *)((int)register0x00000074 + -0x1138));
      puVar5 = *(undefined **)((int)register0x00000074 + -0x1160);
      if (uVar2 == 0) break;
      ERR_error_string_n(uVar2,buf_00,0x100);
      if ((*(uint *)((int)register0x00000074 + -0x1138) & 2) == 0) {
        iVar3 = *(int *)((int)register0x00000074 + -0x1150) + -0x6a30;
      }
      else {
        iVar3 = *(int *)((int)register0x00000074 + -0x1140);
      }
      *(undefined4 *)((int)register0x00000074 + -0x116c) =
           *(undefined4 *)((int)register0x00000074 + -0x1144);
      *(undefined4 *)((int)register0x00000074 + -0x1168) =
           *(undefined4 *)((int)register0x00000074 + -0x113c);
      *(int *)((int)register0x00000074 + -0x1164) = iVar3;
      *(char **)((int)register0x00000074 + -0x1170) = buf_00;
      BIO_snprintf((char *)buf,0x1000,"%lu:%s:%s:%d:%s\n",unaff_s1);
      uVar1 = (**(code **)(*(int *)((int)register0x00000074 + -0x1160) + -0x53b0))(buf);
      unaff_s5 = buf;
      iVar3 = (**(code **)((int)register0x00000074 + -0x1154))(buf,uVar1,u);
      puVar5 = *(undefined **)((int)register0x00000074 + -0x1160);
    } while (0 < iVar3);
    if (*(int *)((int)register0x00000074 + -0x2c) == **(int **)((int)register0x00000074 + -0x114c))
    {
      return;
    }
    pcVar6 = ERR_print_errors_fp;
    (**(code **)(puVar5 + -0x5328))();
    *(char **)((int)register0x00000074 + -0x11a8) = "%lu:%s:%s:%d:%s\n";
    unaff_s0 = (BIO *)((int)register0x00000074 + -0x22f4);
    *(code **)((int)register0x00000074 + -0x1184) = pcVar6;
    *(char ***)((int)register0x00000074 + -0x1188) = file;
    unaff_s8 = (BIO *)((int)register0x00000074 + -0x2304);
    *(char **)((int)register0x00000074 + -0x118c) = buf_00;
    unaff_s7 = (int *)((int)register0x00000074 + -0x22fc);
    *(undefined **)((int)register0x00000074 + -0x230c) = PTR___stack_chk_guard_006aabf0;
    *(char ***)((int)register0x00000074 + -0x1190) = buf;
    unaff_s6 = (char **)((int)register0x00000074 + -0x2300);
    *(int **)((int)register0x00000074 + -0x1194) = (int *)((int)register0x00000074 + -0x113c);
    *(char ***)((int)register0x00000074 + -0x1198) = (char **)((int)register0x00000074 + -0x1140);
    *(int **)((int)register0x00000074 + -0x119c) = (int *)((int)register0x00000074 + -0x1138);
    *(void **)((int)register0x00000074 + -0x11a0) = u;
    *(undefined **)((int)register0x00000074 + -0x2320) = &_gp;
    unaff_s4 = (int *)((int)register0x00000074 + -0x22f8);
    *(char **)((int)register0x00000074 + -0x11a4) = unaff_s1;
    unaff_s3 = "%lu:%s:%s:%d:%s\n";
    unaff_s2 = (int *)0x6716dc;
    *(undefined4 *)((int)register0x00000074 + -0x11ac) =
         *(undefined4 *)PTR___stack_chk_guard_006aabf0;
    (*(code *)PTR_CRYPTO_THREADID_current_006a95ac)(unaff_s0);
    uVar1 = (**(code **)(*(int *)((int)register0x00000074 + -0x2320) + -0x693c))(unaff_s0);
    *(undefined4 *)((int)register0x00000074 + -0x2314) = uVar1;
    *(char **)((int)register0x00000074 + -0x2310) = "s\n";
    do {
      cb = (cb *)unaff_s8;
      u = unaff_s7;
      uVar2 = ERR_get_error_line_data((char **)unaff_s8,unaff_s7,unaff_s6,unaff_s4);
      puVar4 = *(undefined **)((int)register0x00000074 + -0x2320);
      if (uVar2 == 0) break;
      ERR_error_string_n(uVar2,(char *)((int)register0x00000074 + -0x22ac),0x100);
      if ((*(uint *)((int)register0x00000074 + -0x22f8) & 2) == 0) {
        iVar3 = *(int *)((int)register0x00000074 + -0x2310) + -0x6a30;
      }
      else {
        iVar3 = *(int *)((int)register0x00000074 + -0x2300);
      }
      unaff_s1 = (char *)((int)register0x00000074 + -0x21ac);
      *(undefined4 *)((int)register0x00000074 + -9000) =
           *(undefined4 *)((int)register0x00000074 + -0x22fc);
      *(undefined4 *)((int)register0x00000074 + -0x232c) =
           *(undefined4 *)((int)register0x00000074 + -0x2304);
      *(char **)((int)register0x00000074 + -0x2330) = (char *)((int)register0x00000074 + -0x22ac);
      unaff_s0 = (BIO *)((int)register0x00000074 + -0x22ec);
      *(int *)((int)register0x00000074 + -0x2324) = iVar3;
      BIO_snprintf(unaff_s1,0x1000,"%lu:%s:%s:%d:%s\n",
                   *(undefined4 *)((int)register0x00000074 + -0x2314));
      type = BIO_s_file();
      BIO_set(unaff_s0,type);
      BIO_ctrl(unaff_s0,0x6a,0,unaff_s5);
      cb = (cb *)unaff_s0;
      u = unaff_s2;
      iVar3 = BIO_printf(unaff_s0,"%s",unaff_s1);
      puVar4 = *(undefined **)((int)register0x00000074 + -0x2320);
    } while (0 < iVar3);
    if (*(int *)((int)register0x00000074 + -0x11ac) == **(int **)((int)register0x00000074 + -0x230c)
       ) {
      return;
    }
    unaff_retaddr = ERR_print_errors_cb;
    (**(code **)(puVar4 + -0x5328))();
    register0x00000074 = (BADSPACEBASE *)((int)register0x00000074 + -0x2340);
  } while( true );
}

