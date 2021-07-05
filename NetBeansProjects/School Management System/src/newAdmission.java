import java.awt.Color;
import java.sql.*;
import javax.swing.*;

public class newAdmission extends javax.swing.JFrame {
    static Connection con;
    Statement s;
    PreparedStatement pst;
    Color c = new Color(45,118,232);

    public newAdmission() {
        connection();
        initComponents();
    }

    public static void connection(){
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            con = DriverManager.getConnection("jdbc:mysql://localhost:3306/sms","root","admin");
            System.out.println("connected");
        } catch (Exception ex) {
            ex.printStackTrace();
        }        
    }
    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        jPanel2 = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        close = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        jLabel9 = new javax.swing.JLabel();
        jLabel10 = new javax.swing.JLabel();
        jLabel11 = new javax.swing.JLabel();
        jLabel13 = new javax.swing.JLabel();
        jLabel14 = new javax.swing.JLabel();
        jLabel15 = new javax.swing.JLabel();
        jLabel16 = new javax.swing.JLabel();
        fathernametxt = new javax.swing.JTextField();
        regtxt = new javax.swing.JTextField();
        nametxt = new javax.swing.JTextField();
        doatxt = new javax.swing.JTextField();
        previousschooltxt = new javax.swing.JTextField();
        femaletxt = new javax.swing.JRadioButton();
        maletxt = new javax.swing.JRadioButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        addresstxt = new javax.swing.JTextArea();
        dobtxt = new javax.swing.JTextField();
        fathernotxt = new javax.swing.JTextField();
        motheracttxt = new javax.swing.JTextField();
        whatsappnotxt = new javax.swing.JTextField();
        mothernotxt = new javax.swing.JTextField();
        fatherocctxt = new javax.swing.JTextField();
        classtxt = new javax.swing.JTextField();
        jLabel7 = new javax.swing.JLabel();
        mothernametxt = new javax.swing.JTextField();
        save = new javax.swing.JButton();
        jLabel18 = new javax.swing.JLabel();
        jLabel12 = new javax.swing.JLabel();
        muslimtxt = new javax.swing.JRadioButton();
        nonmuslimtxt = new javax.swing.JRadioButton();
        jLabel17 = new javax.swing.JLabel();
        cclasstxt = new javax.swing.JTextField();
        jLabel19 = new javax.swing.JLabel();
        feetxt = new javax.swing.JTextField();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setUndecorated(true);
        setResizable(false);

        jPanel1.setBackground(new java.awt.Color(255, 255, 255));
        jPanel1.setBorder(javax.swing.BorderFactory.createMatteBorder(3, 3, 3, 3, new java.awt.Color(45, 118, 232)));
        jPanel1.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jPanel2.setBackground(new java.awt.Color(45, 118, 232));

        jLabel1.setFont(new java.awt.Font("Tahoma", 1, 24)); // NOI18N
        jLabel1.setForeground(new java.awt.Color(255, 255, 255));
        jLabel1.setText("Admission Form");

        close.setFont(new java.awt.Font("Tahoma", 1, 24)); // NOI18N
        close.setForeground(new java.awt.Color(255, 255, 255));
        close.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        close.setText("<");
        close.setVerticalAlignment(javax.swing.SwingConstants.TOP);
        close.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                closeMouseClicked(evt);
            }
        });

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addComponent(close, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(177, 177, 177)
                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 223, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(233, Short.MAX_VALUE))
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel2Layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 42, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addComponent(close)
                .addGap(0, 0, Short.MAX_VALUE))
        );

        jPanel1.add(jPanel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 0, 660, 60));

        jLabel2.setFont(new java.awt.Font("Times New Roman", 0, 14)); // NOI18N
        jLabel2.setText("Name of Previous School");
        jPanel1.add(jLabel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 640, 160, -1));

        jLabel3.setFont(new java.awt.Font("Times New Roman", 0, 14)); // NOI18N
        jLabel3.setText("Registration No.");
        jPanel1.add(jLabel3, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 100, 100, -1));

        jLabel4.setFont(new java.awt.Font("Times New Roman", 0, 14)); // NOI18N
        jLabel4.setText("Date of Admission");
        jPanel1.add(jLabel4, new org.netbeans.lib.awtextra.AbsoluteConstraints(340, 100, 110, -1));

        jLabel5.setFont(new java.awt.Font("Times New Roman", 0, 14)); // NOI18N
        jLabel5.setText("Student Name");
        jPanel1.add(jLabel5, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 170, 100, -1));

        jLabel6.setFont(new java.awt.Font("Times New Roman", 0, 14)); // NOI18N
        jLabel6.setText("Father's Name");
        jPanel1.add(jLabel6, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 220, 100, -1));

        jLabel8.setFont(new java.awt.Font("Times New Roman", 0, 14)); // NOI18N
        jLabel8.setText("Date of Birth");
        jPanel1.add(jLabel8, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 260, 100, -1));

        jLabel9.setFont(new java.awt.Font("Times New Roman", 0, 14)); // NOI18N
        jLabel9.setText("Gender");
        jPanel1.add(jLabel9, new org.netbeans.lib.awtextra.AbsoluteConstraints(420, 170, 60, 20));

        jLabel10.setFont(new java.awt.Font("Times New Roman", 0, 14)); // NOI18N
        jLabel10.setText("Address");
        jPanel1.add(jLabel10, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 370, 100, -1));

        jLabel11.setFont(new java.awt.Font("Times New Roman", 0, 14)); // NOI18N
        jLabel11.setText("Mother Tel No.");
        jPanel1.add(jLabel11, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 530, 100, 20));

        jLabel13.setFont(new java.awt.Font("Times New Roman", 0, 14)); // NOI18N
        jLabel13.setText("Whatsapp No.");
        jPanel1.add(jLabel13, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 580, 90, -1));

        jLabel14.setFont(new java.awt.Font("Times New Roman", 0, 14)); // NOI18N
        jLabel14.setText("Class of Admission");
        jPanel1.add(jLabel14, new org.netbeans.lib.awtextra.AbsoluteConstraints(340, 590, 110, 20));

        jLabel15.setFont(new java.awt.Font("Times New Roman", 0, 14)); // NOI18N
        jLabel15.setText("Mother Activities");
        jPanel1.add(jLabel15, new org.netbeans.lib.awtextra.AbsoluteConstraints(340, 540, 100, -1));

        jLabel16.setFont(new java.awt.Font("Times New Roman", 0, 14)); // NOI18N
        jLabel16.setText("Father Occupation");
        jPanel1.add(jLabel16, new org.netbeans.lib.awtextra.AbsoluteConstraints(340, 490, 130, -1));

        fathernametxt.setToolTipText("");
        fathernametxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(fathernametxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(130, 220, 190, 20));

        regtxt.setToolTipText("");
        regtxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(regtxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(140, 100, 180, 20));

        nametxt.setToolTipText("");
        nametxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(nametxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(130, 170, 270, 20));

        doatxt.setToolTipText("");
        doatxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(doatxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(460, 100, 150, 20));

        previousschooltxt.setToolTipText("");
        previousschooltxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(previousschooltxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(190, 640, 420, 20));

        femaletxt.setText("Female");
        femaletxt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                femaletxtActionPerformed(evt);
            }
        });
        jPanel1.add(femaletxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(540, 170, -1, -1));

        maletxt.setText("Male");
        maletxt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                maletxtActionPerformed(evt);
            }
        });
        jPanel1.add(maletxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(480, 170, -1, -1));

        addresstxt.setColumns(20);
        addresstxt.setRows(5);
        jScrollPane1.setViewportView(addresstxt);

        jPanel1.add(jScrollPane1, new org.netbeans.lib.awtextra.AbsoluteConstraints(130, 360, 480, 90));

        dobtxt.setToolTipText("");
        dobtxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(dobtxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(130, 260, 190, 20));

        fathernotxt.setToolTipText("");
        fathernotxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(fathernotxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(130, 480, 180, 20));

        motheracttxt.setToolTipText("");
        motheracttxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(motheracttxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(460, 540, 150, 20));

        whatsappnotxt.setToolTipText("");
        whatsappnotxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(whatsappnotxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(130, 580, 180, 20));

        mothernotxt.setToolTipText("");
        mothernotxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        mothernotxt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                mothernotxtActionPerformed(evt);
            }
        });
        jPanel1.add(mothernotxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(130, 530, 180, 20));

        fatherocctxt.setToolTipText("");
        fatherocctxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(fatherocctxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(460, 490, 150, 20));

        classtxt.setToolTipText("");
        classtxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(classtxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(460, 590, 150, 20));

        jLabel7.setFont(new java.awt.Font("Times New Roman", 0, 14)); // NOI18N
        jLabel7.setText("Mother Name");
        jPanel1.add(jLabel7, new org.netbeans.lib.awtextra.AbsoluteConstraints(340, 220, 100, -1));

        mothernametxt.setToolTipText("");
        mothernametxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(mothernametxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(430, 220, 180, 20));

        save.setBackground(new java.awt.Color(45, 118, 232));
        save.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        save.setForeground(new java.awt.Color(255, 255, 255));
        save.setText("Save");
        save.setBorderPainted(false);
        save.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        save.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                saveActionPerformed(evt);
            }
        });
        jPanel1.add(save, new org.netbeans.lib.awtextra.AbsoluteConstraints(530, 680, 90, 30));

        jLabel18.setFont(new java.awt.Font("Times New Roman", 0, 14)); // NOI18N
        jLabel18.setText("Father Tel No.");
        jPanel1.add(jLabel18, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 480, 100, 20));

        jLabel12.setFont(new java.awt.Font("Times New Roman", 0, 14)); // NOI18N
        jLabel12.setText("Religion");
        jPanel1.add(jLabel12, new org.netbeans.lib.awtextra.AbsoluteConstraints(340, 260, 100, -1));

        muslimtxt.setText("Musim");
        muslimtxt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                muslimtxtActionPerformed(evt);
            }
        });
        jPanel1.add(muslimtxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(430, 260, -1, -1));

        nonmuslimtxt.setText("Non-Muslim");
        nonmuslimtxt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                nonmuslimtxtActionPerformed(evt);
            }
        });
        jPanel1.add(nonmuslimtxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(500, 260, -1, -1));

        jLabel17.setFont(new java.awt.Font("Times New Roman", 0, 14)); // NOI18N
        jLabel17.setText("Class");
        jPanel1.add(jLabel17, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 300, 100, -1));

        cclasstxt.setToolTipText("");
        cclasstxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(cclasstxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(130, 300, 190, 20));

        jLabel19.setFont(new java.awt.Font("Times New Roman", 0, 14)); // NOI18N
        jLabel19.setText("Fee");
        jPanel1.add(jLabel19, new org.netbeans.lib.awtextra.AbsoluteConstraints(340, 300, 100, -1));

        feetxt.setToolTipText("");
        feetxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(feetxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(430, 300, 180, 20));

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, 658, javax.swing.GroupLayout.PREFERRED_SIZE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, 730, Short.MAX_VALUE)
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void maletxtActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_maletxtActionPerformed
        // TODO add your handling code here:
        if(maletxt.isSelected())
            femaletxt.setSelected(false);
    }//GEN-LAST:event_maletxtActionPerformed

    private void femaletxtActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_femaletxtActionPerformed
        // TODO add your handling code here:
        if(femaletxt.isSelected())
            maletxt.setSelected(false);
    }//GEN-LAST:event_femaletxtActionPerformed

    private void saveActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_saveActionPerformed
        try {
            String regno = regtxt.getText();
            String doa = doatxt.getText();
            String name = nametxt.getText();
            String fathername = fathernametxt.getText();
            String mothername = mothernametxt.getText();
            String dob = dobtxt.getText();
            String cclass = cclasstxt.getText();
            String fee = feetxt.getText();

            String gender=null;
            if(maletxt.isSelected())
                gender = "male";
            else if(femaletxt.isSelected())
                gender = "female";

            String address = addresstxt.getText();
            String fatherno = fathernotxt.getText();
            String motherno = mothernotxt.getText();
            String whatsappno = whatsappnotxt.getText();
            String fatherocc = fatherocctxt.getText();
            String motheract = motheracttxt.getText();
            String classofadd = classtxt.getText();
            
            String religion = null;
            if(muslimtxt.isSelected())
                religion = "muslim";
            else if(nonmuslimtxt.isSelected())
                religion = "non muslim";
            
            String previous = previousschooltxt.getText();
        
        
            pst = con.prepareStatement("insert into students(regno,name,doa,fathername,mothername,dob,gender,address,fatherphoneno,fatheroccupation,motherphoneno,motheract,whatsappno,classofadd,previousschool,religion,fee,class) values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
            pst.setString(1, regno);
            pst.setString(2, name);
            pst.setString(3, doa);
            pst.setString(4, fathername);
            pst.setString(5, mothername);
            pst.setString(6, dob);
            pst.setString(7, gender);
            pst.setString(8, address);
            pst.setString(9, fatherno);
            pst.setString(10, fatherocc);
            pst.setString(11, motherno);
            pst.setString(12, motheract);
            pst.setString(13, whatsappno);
            pst.setString(14, classofadd);
            pst.setString(15, previous);  
            pst.setString(16, religion);
            pst.setString(17, fee);  
            pst.setString(18, cclass);
            
            pst.executeUpdate();
            
            JOptionPane.showMessageDialog(this,"Data Saved successfully..");
            
            mainFrame MF = new mainFrame();
            MF.setVisible(true);
            this.hide();
            
        } catch (Exception ex) {
            ex.printStackTrace();
            JOptionPane.showMessageDialog(this,"Data missing.. \nSaving failed");
        }
        
    }//GEN-LAST:event_saveActionPerformed

    private void muslimtxtActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_muslimtxtActionPerformed
        // TODO add your handling code here:
        if(muslimtxt.isSelected())
            nonmuslimtxt.setSelected(false);
    }//GEN-LAST:event_muslimtxtActionPerformed

    private void nonmuslimtxtActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_nonmuslimtxtActionPerformed
        // TODO add your handling code here:
        if(nonmuslimtxt.isSelected())
            muslimtxt.setSelected(false);
    }//GEN-LAST:event_nonmuslimtxtActionPerformed

    private void mothernotxtActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_mothernotxtActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_mothernotxtActionPerformed

    private void closeMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_closeMouseClicked
        mainFrame MF = new mainFrame();
        MF.setVisible(true);
        //System.exit(0);
        this.hide();
    }//GEN-LAST:event_closeMouseClicked

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(newAdmission.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(newAdmission.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(newAdmission.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(newAdmission.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new newAdmission().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextArea addresstxt;
    private javax.swing.JTextField cclasstxt;
    private javax.swing.JTextField classtxt;
    private javax.swing.JLabel close;
    private javax.swing.JTextField doatxt;
    private javax.swing.JTextField dobtxt;
    private javax.swing.JTextField fathernametxt;
    private javax.swing.JTextField fathernotxt;
    private javax.swing.JTextField fatherocctxt;
    private javax.swing.JTextField feetxt;
    private javax.swing.JRadioButton femaletxt;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel11;
    private javax.swing.JLabel jLabel12;
    private javax.swing.JLabel jLabel13;
    private javax.swing.JLabel jLabel14;
    private javax.swing.JLabel jLabel15;
    private javax.swing.JLabel jLabel16;
    private javax.swing.JLabel jLabel17;
    private javax.swing.JLabel jLabel18;
    private javax.swing.JLabel jLabel19;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JRadioButton maletxt;
    private javax.swing.JTextField motheracttxt;
    private javax.swing.JTextField mothernametxt;
    private javax.swing.JTextField mothernotxt;
    private javax.swing.JRadioButton muslimtxt;
    private javax.swing.JTextField nametxt;
    private javax.swing.JRadioButton nonmuslimtxt;
    private javax.swing.JTextField previousschooltxt;
    private javax.swing.JTextField regtxt;
    private javax.swing.JButton save;
    private javax.swing.JTextField whatsappnotxt;
    // End of variables declaration//GEN-END:variables
}
