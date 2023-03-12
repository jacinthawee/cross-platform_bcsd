
void print_stats(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = (*(code *)PTR_SSL_CTX_ctrl_006a884c)(param_2,0x14,0,0);
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%4ld items in the session cache\n",uVar1);
  uVar1 = (*(code *)PTR_SSL_CTX_ctrl_006a884c)(param_2,0x15,0,0);
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%4ld client connects (SSL_connect())\n",uVar1);
  uVar1 = (*(code *)PTR_SSL_CTX_ctrl_006a884c)(param_2,0x17,0,0);
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%4ld client renegotiates (SSL_connect())\n",uVar1);
  uVar1 = (*(code *)PTR_SSL_CTX_ctrl_006a884c)(param_2,0x16,0,0);
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%4ld client connects that finished\n",uVar1);
  uVar1 = (*(code *)PTR_SSL_CTX_ctrl_006a884c)(param_2,0x18,0,0);
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%4ld server accepts (SSL_accept())\n",uVar1);
  uVar1 = (*(code *)PTR_SSL_CTX_ctrl_006a884c)(param_2,0x1a,0,0);
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%4ld server renegotiates (SSL_accept())\n",uVar1);
  uVar1 = (*(code *)PTR_SSL_CTX_ctrl_006a884c)(param_2,0x19,0,0);
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%4ld server accepts that finished\n",uVar1);
  uVar1 = (*(code *)PTR_SSL_CTX_ctrl_006a884c)(param_2,0x1b,0,0);
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%4ld session cache hits\n",uVar1);
  uVar1 = (*(code *)PTR_SSL_CTX_ctrl_006a884c)(param_2,0x1d,0,0);
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%4ld session cache misses\n",uVar1);
  uVar1 = (*(code *)PTR_SSL_CTX_ctrl_006a884c)(param_2,0x1e,0,0);
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%4ld session cache timeouts\n",uVar1);
  uVar1 = (*(code *)PTR_SSL_CTX_ctrl_006a884c)(param_2,0x1c,0,0);
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%4ld callback cache hits\n",uVar1);
  uVar1 = (*(code *)PTR_SSL_CTX_ctrl_006a884c)(param_2,0x1f,0,0);
  uVar2 = (*(code *)PTR_SSL_CTX_ctrl_006a884c)(param_2,0x2b,0,0);
                    /* WARNING: Could not recover jumptable at 0x004423a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_BIO_printf_006a7f38)
            (param_1,"%4ld cache full overflows (%ld allowed)\n",uVar1,uVar2);
  return;
}

