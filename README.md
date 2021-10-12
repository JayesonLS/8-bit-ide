# 8-bit-ide

WIP on a solid state replacement for 8 bit IDE hard drives.

This project is looking at implementing replacements for:

1. The somewhat standard drive type used by PCs with 8 bit ISA bus.
   This uses a the same style of 40 pin header as ATA however
   the pinout and protocols are different. This is referred to
   by various names such as XT-BUS, XT-IDE, IDE-XT or XTA. We
   will refer to this as XTA.
   
   XTA should not be confused with the much more modern XTIDE
   Universal BIOS and cards which were created to adapt ATA
   devices to XT PCs. It should also not be confused with the ATA
   8 bit transfer mode available in many compact flash cards.
   
2. The IBM proprietary 8 bit IDE hard drive type with card edge
   connector. These were used in the IBM PS/2 Model 25 and Model 30
   as well as early 8086 and 80286 IBM PS/1's. We will refer
   to this IBM 8-bit DBA (Direct BUS Attachment). 

   IBM 8-bit DBA should not be confused with IBM's MCA 
   (Microchannel) DBA hard drive type. This type uses a card edge
   connector and integrates the drive controller into the drive.
   To the system BIOS, these devices look like the IBM MCA ESDI
   hard drive controller card and so are sometimes confusingly 
   referred to as ESDI hard drives. This project does not plan
   to implement a replacement for the IBM MCA DBA "ESDI" drives.

More information available in this VCFED discussion:
https://www.vcfed.org/forum/forum/genres/pcs-and-clones/1224016-8-bit-ide-xta-replacement-project
