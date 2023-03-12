
undefined4 ssl_callback_ctrl(int param_1,int param_2,cb *param_3)

{
  undefined4 uVar1;
  
  if (param_2 != 0xe) {
                    /* WARNING: Could not recover jumptable at 0x004b9a90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)PTR_BIO_callback_ctrl_006a8428)((**(SSL ***)(param_1 + 0x20))->rbio);
    return uVar1;
  }
  SSL_set_info_callback(**(SSL ***)(param_1 + 0x20),param_3);
  return 1;
}

