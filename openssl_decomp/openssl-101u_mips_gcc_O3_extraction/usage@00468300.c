
void usage(void)

{
  undefined *puVar1;
  
  puVar1 = PTR_bio_err_006a6e3c;
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)PTR_bio_err_006a6e3c,"Usage: pkeyutl [options]\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"-in file        input file\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"-out file       output file\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar1,"-sigfile file signature file (verify operation only)\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"-inkey file     input key\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar1,"-keyform arg    private key format - default PEM\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar1,"-pubin          input is a public key\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar1,"-certin         input is a certificate carrying a public key\n")
  ;
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"-pkeyopt X:Y    public key options\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar1,"-sign           sign with private key\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar1,"-verify         verify with public key\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar1,"-verifyrecover  verify with public key, recover original data\n"
            );
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar1,"-encrypt        encrypt with public key\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar1,"-decrypt        decrypt with private key\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"-derive         derive shared secret\n")
  ;
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"-hexdump        hex dump output\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar1,"-engine e       use engine e, possibly a hardware device.\n");
                    /* WARNING: Could not recover jumptable at 0x004684cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"-passin arg     pass phrase source\n");
  return;
}

