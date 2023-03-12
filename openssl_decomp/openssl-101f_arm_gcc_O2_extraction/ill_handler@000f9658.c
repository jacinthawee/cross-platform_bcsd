
void ill_handler(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
                    /* WARNING: Subroutine does not return */
  __longjmp_chk(&ill_jmp,param_1,param_3,param_4,param_4);
}

