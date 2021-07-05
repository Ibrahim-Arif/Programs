import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;

public class searchFrame extends javax.swing.JFrame {
    static Connection con;
    PreparedStatement pst;
    static String CS;
    static String nameS;
    int flagForUpdate=0;
    
    public searchFrame() {
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
        searchclasstxt = new javax.swing.JComboBox<>();
        namesearchtxt = new javax.swing.JTextField();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        jLabel9 = new javax.swing.JLabel();
        jLabel10 = new javax.swing.JLabel();
        jLabel11 = new javax.swing.JLabel();
        jLabel12 = new javax.swing.JLabel();
        jLabel13 = new javax.swing.JLabel();
        jLabel14 = new javax.swing.JLabel();
        jLabel15 = new javax.swing.JLabel();
        jLabel16 = new javax.swing.JLabel();
        jLabel17 = new javax.swing.JLabel();
        jLabel18 = new javax.swing.JLabel();
        mothertxt = new javax.swing.JTextField();
        nametxt = new javax.swing.JTextField();
        fathertxt = new javax.swing.JTextField();
        doatxt = new javax.swing.JTextField();
        fatherocctxt = new javax.swing.JTextField();
        whatsapptxt = new javax.swing.JTextField();
        classtxt = new javax.swing.JTextField();
        addresstxt = new javax.swing.JTextField();
        regiliontxt = new javax.swing.JTextField();
        motherphonetxt = new javax.swing.JTextField();
        motherocctxt = new javax.swing.JTextField();
        previoustxt = new javax.swing.JTextField();
        fatherphonetxt = new javax.swing.JTextField();
        dobtxt = new javax.swing.JTextField();
        regnotxt = new javax.swing.JTextField();
        jPanel3 = new javax.swing.JPanel();
        Close = new javax.swing.JButton();
        search = new javax.swing.JButton();
        update = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setUndecorated(true);

        jPanel1.setBackground(new java.awt.Color(255, 255, 255));
        jPanel1.setBorder(javax.swing.BorderFactory.createMatteBorder(3, 3, 3, 3, new java.awt.Color(45, 118, 232)));
        jPanel1.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jPanel2.setBackground(new java.awt.Color(45, 118, 232));

        jLabel1.setFont(new java.awt.Font("Tahoma", 1, 24)); // NOI18N
        jLabel1.setForeground(new java.awt.Color(255, 255, 255));
        jLabel1.setText("Search & Update");

        close.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
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
                .addComponent(close, javax.swing.GroupLayout.PREFERRED_SIZE, 29, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 252, Short.MAX_VALUE)
                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 223, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(266, 266, 266))
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addComponent(close)
                .addGap(0, 0, Short.MAX_VALUE))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel2Layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 42, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
        );

        jPanel1.add(jPanel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 0, 770, 60));

        jLabel2.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel2.setText("Select Class");
        jPanel1.add(jLabel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(70, 100, 80, 20));

        jLabel3.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel3.setText("Enter Name");
        jPanel1.add(jLabel3, new org.netbeans.lib.awtextra.AbsoluteConstraints(320, 100, -1, -1));

        searchclasstxt.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Select Class", "play group", "nursury", "one", "two", "three", "four", "five", "six", "seven", "eight" }));
        searchclasstxt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                searchclasstxtActionPerformed(evt);
            }
        });
        jPanel1.add(searchclasstxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(160, 100, 120, -1));

        namesearchtxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(namesearchtxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(410, 90, 180, 30));

        jLabel4.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel4.setText("Class");
        jPanel1.add(jLabel4, new org.netbeans.lib.awtextra.AbsoluteConstraints(400, 290, 120, 30));

        jLabel5.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel5.setText("Name");
        jPanel1.add(jLabel5, new org.netbeans.lib.awtextra.AbsoluteConstraints(70, 180, 120, -1));

        jLabel6.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel6.setText("Father Name");
        jPanel1.add(jLabel6, new org.netbeans.lib.awtextra.AbsoluteConstraints(70, 220, 120, -1));

        jLabel7.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel7.setText("Mother name");
        jPanel1.add(jLabel7, new org.netbeans.lib.awtextra.AbsoluteConstraints(70, 260, 120, -1));

        jLabel8.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel8.setText("Whatsapp no.");
        jPanel1.add(jLabel8, new org.netbeans.lib.awtextra.AbsoluteConstraints(70, 300, 120, -1));

        jLabel9.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel9.setText("Father occopution");
        jPanel1.add(jLabel9, new org.netbeans.lib.awtextra.AbsoluteConstraints(70, 340, 120, -1));

        jLabel10.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel10.setText("DOA");
        jPanel1.add(jLabel10, new org.netbeans.lib.awtextra.AbsoluteConstraints(400, 380, 110, 20));

        jLabel11.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel11.setText("Address");
        jPanel1.add(jLabel11, new org.netbeans.lib.awtextra.AbsoluteConstraints(70, 420, 120, 20));

        jLabel12.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel12.setText("Regilion");
        jPanel1.add(jLabel12, new org.netbeans.lib.awtextra.AbsoluteConstraints(70, 460, 130, -1));

        jLabel13.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel13.setText("Registration no");
        jPanel1.add(jLabel13, new org.netbeans.lib.awtextra.AbsoluteConstraints(400, 180, 130, 20));

        jLabel14.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel14.setText("Mother phone no.");
        jPanel1.add(jLabel14, new org.netbeans.lib.awtextra.AbsoluteConstraints(400, 260, 130, -1));

        jLabel15.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel15.setText("Previous School");
        jPanel1.add(jLabel15, new org.netbeans.lib.awtextra.AbsoluteConstraints(400, 460, 130, -1));

        jLabel16.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel16.setText("Father phone no.");
        jPanel1.add(jLabel16, new org.netbeans.lib.awtextra.AbsoluteConstraints(400, 220, 130, -1));

        jLabel17.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel17.setText("Mother activities");
        jPanel1.add(jLabel17, new org.netbeans.lib.awtextra.AbsoluteConstraints(400, 340, 130, -1));

        jLabel18.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel18.setText("DOB");
        jPanel1.add(jLabel18, new org.netbeans.lib.awtextra.AbsoluteConstraints(70, 380, 130, 20));

        mothertxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(mothertxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(190, 250, 190, 30));

        nametxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(nametxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(190, 170, 190, 30));

        fathertxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(fathertxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(190, 210, 190, 30));

        doatxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(doatxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(530, 370, 190, 30));

        fatherocctxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(fatherocctxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(190, 330, 190, 30));

        whatsapptxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(whatsapptxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(190, 290, 190, 30));

        classtxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(classtxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(530, 290, 190, 30));

        addresstxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(addresstxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(190, 410, 530, 30));

        regiliontxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(regiliontxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(190, 450, 190, 30));

        motherphonetxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(motherphonetxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(530, 250, 190, 30));

        motherocctxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(motherocctxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(530, 330, 190, 30));

        previoustxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(previoustxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(530, 450, 190, 30));

        fatherphonetxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(fatherphonetxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(530, 210, 190, 30));

        dobtxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        dobtxt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                dobtxtActionPerformed(evt);
            }
        });
        jPanel1.add(dobtxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(190, 370, 190, 30));

        regnotxt.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        jPanel1.add(regnotxt, new org.netbeans.lib.awtextra.AbsoluteConstraints(530, 170, 190, 30));

        jPanel3.setBackground(new java.awt.Color(255, 255, 255));
        jPanel3.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));

        javax.swing.GroupLayout jPanel3Layout = new javax.swing.GroupLayout(jPanel3);
        jPanel3.setLayout(jPanel3Layout);
        jPanel3Layout.setHorizontalGroup(
            jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
        );
        jPanel3Layout.setVerticalGroup(
            jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
        );

        jPanel1.add(jPanel3, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 140, 750, 10));

        Close.setBackground(new java.awt.Color(45, 118, 232));
        Close.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        Close.setForeground(new java.awt.Color(255, 255, 255));
        Close.setText("Close");
        Close.setBorderPainted(false);
        Close.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                CloseMouseClicked(evt);
            }
        });
        jPanel1.add(Close, new org.netbeans.lib.awtextra.AbsoluteConstraints(530, 510, 90, 30));

        search.setBackground(new java.awt.Color(45, 118, 232));
        search.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        search.setForeground(new java.awt.Color(255, 255, 255));
        search.setText("Search");
        search.setBorderPainted(false);
        search.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                searchMouseClicked(evt);
            }
        });
        jPanel1.add(search, new org.netbeans.lib.awtextra.AbsoluteConstraints(640, 90, 90, 30));

        update.setBackground(new java.awt.Color(45, 118, 232));
        update.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        update.setForeground(new java.awt.Color(255, 255, 255));
        update.setText("Update");
        update.setBorderPainted(false);
        update.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                updateMouseClicked(evt);
            }
        });
        jPanel1.add(update, new org.netbeans.lib.awtextra.AbsoluteConstraints(630, 510, 90, 30));

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, 562, Short.MAX_VALUE)
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void closeMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_closeMouseClicked
        mainFrame MF = new mainFrame();
        this.hide();
        MF.setVisible(true);
        this.hide();
    }//GEN-LAST:event_closeMouseClicked

    private void searchclasstxtActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_searchclasstxtActionPerformed
        // TODO add your handling code here:
        searchclasstxt.setEnabled(true);
        namesearchtxt.setEnabled(true);
        search.setEnabled(true);
    }//GEN-LAST:event_searchclasstxtActionPerformed

    private void searchMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_searchMouseClicked
        CS = searchclasstxt.getSelectedItem().toString();
        nameS = namesearchtxt.getText();
        
        search(CS,nameS);
    }//GEN-LAST:event_searchMouseClicked

    public void search(String CS, String nameS){
        try {            
            Statement s = con.createStatement();
            ResultSet rs = s.executeQuery("select *from students where class= '"+CS+"' and name= '"+nameS+"' ");
            rs.next();
            //System.out.println("aaa");
            
            nametxt.setText(rs.getString("name"));
            fathertxt.setText(rs.getString("fathername"));
            mothertxt.setText(rs.getString("mothername"));
            whatsapptxt.setText(rs.getString("whatsappno"));
            fatherocctxt.setText(rs.getString("fatheroccupation"));
            doatxt.setText(rs.getString("doa"));
            classtxt.setText(rs.getString("class"));
            addresstxt.setText(rs.getString("address"));
            regnotxt.setText(rs.getString("regno"));
            regiliontxt.setText(rs.getString("religion"));
            motherphonetxt.setText(rs.getString("motherphoneno"));
            fatherphonetxt.setText(rs.getString("fatherphoneno"));
            motherocctxt.setText(rs.getString("motheract"));
            dobtxt.setText(rs.getString("dob"));
            previoustxt.setText(rs.getString("previousschool"));
            s.close();
            rs.close();
            
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
    public void search(String regno){
        try {            
            Statement s = con.createStatement();
            ResultSet rs = s.executeQuery("select *from students where regno= '"+regno+"' ");
            rs.next();
            //System.out.println("aaa");
            
            nametxt.setText(rs.getString("name"));
            fathertxt.setText(rs.getString("fathername"));
            mothertxt.setText(rs.getString("mothername"));
            whatsapptxt.setText(rs.getString("whatsappno"));
            fatherocctxt.setText(rs.getString("fatheroccupation"));
            doatxt.setText(rs.getString("doa"));
            classtxt.setText(rs.getString("class"));
            addresstxt.setText(rs.getString("address"));
            regnotxt.setText(rs.getString("regno"));
            regiliontxt.setText(rs.getString("religion"));
            motherphonetxt.setText(rs.getString("motherphoneno"));
            fatherphonetxt.setText(rs.getString("fatherphoneno"));
            motherocctxt.setText(rs.getString("motheract"));
            dobtxt.setText(rs.getString("dob"));
            previoustxt.setText(rs.getString("previousschool"));
            s.close();
            rs.close();
            
            flagForUpdate=1;
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
    
    private void updateMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_updateMouseClicked
        // TODO add your handling code here:
        try {
            String regno = regnotxt.getText();
            String doa = doatxt.getText();
            String name = nametxt.getText();
            String fathername = fathertxt.getText();
            String mothername = mothertxt.getText();
            String dob = dobtxt.getText();
            String address = addresstxt.getText();
            String fatherno = fatherphonetxt.getText();
            String motherno = motherphonetxt.getText();
            String whatsappno = whatsapptxt.getText();
            String fatherocc = fatherocctxt.getText();
            String motheract = motherocctxt.getText();
            String cclass = classtxt.getText();
            String religion = regiliontxt.getText();
            String previous = previoustxt.getText();
        
        
            Statement s = con.createStatement();
            if(flagForUpdate == 0){
            s.execute("update students "
                    + "set name='"+name+"' "
                    + ", doa='"+doa+"' "
                    + ", fathername='"+fathername+"' "
                    + ", mothername='"+mothername+"' "
                    + ", dob='"+dob+"' "
                    + ", address='"+address+"' "
                    + ", fatherphoneno='"+fatherno+"' "
                    + ", fatheroccupation='"+fatherocc+"' "
                    + ", motherphoneno='"+motherno+"' "
                    + ", motheract='"+motheract+"' "
                    + ", whatsappno='"+whatsappno+"' "
                    + ", class='"+cclass+"' "
                    + ", previousschool='"+previous+"' "
                    + ", religion='"+religion+"' "      
                    + " where class='"+CS+"' "
                    + " and name='"+nameS+"'  ");
            }
            else if(flagForUpdate == 1){
                s.execute("update students "
                    + "set name='"+name+"' "
                    + ", doa='"+doa+"' "
                    + ", fathername='"+fathername+"' "
                    + ", mothername='"+mothername+"' "
                    + ", dob='"+dob+"' "
                    + ", address='"+address+"' "
                    + ", fatherphoneno='"+fatherno+"' "
                    + ", fatheroccupation='"+fatherocc+"' "
                    + ", motherphoneno='"+motherno+"' "
                    + ", motheract='"+motheract+"' "
                    + ", whatsappno='"+whatsappno+"' "
                    + ", class='"+cclass+"' "
                    + ", previousschool='"+previous+"' "
                    + ", religion='"+religion+"' "      
                    + " where regno='"+regno+"' ");
                
                flagForUpdate=0;
            }
            JOptionPane.showMessageDialog(this,"Data Updated successfully..");
                   
        } catch(Exception e){
            e.printStackTrace();
        }
    }//GEN-LAST:event_updateMouseClicked

    private void CloseMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_CloseMouseClicked
        // TODO add your handling code here:
        mainFrame MF = new mainFrame();
        MF.setVisible(true);
        this.hide();
    }//GEN-LAST:event_CloseMouseClicked

    private void dobtxtActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_dobtxtActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_dobtxtActionPerformed

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
            java.util.logging.Logger.getLogger(searchFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(searchFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(searchFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(searchFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new searchFrame().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton Close;
    private javax.swing.JTextField addresstxt;
    private javax.swing.JTextField classtxt;
    private javax.swing.JLabel close;
    private javax.swing.JTextField doatxt;
    private javax.swing.JTextField dobtxt;
    private javax.swing.JTextField fatherocctxt;
    private javax.swing.JTextField fatherphonetxt;
    private javax.swing.JTextField fathertxt;
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
    private javax.swing.JPanel jPanel3;
    private javax.swing.JTextField motherocctxt;
    private javax.swing.JTextField motherphonetxt;
    private javax.swing.JTextField mothertxt;
    private javax.swing.JTextField namesearchtxt;
    private javax.swing.JTextField nametxt;
    private javax.swing.JTextField previoustxt;
    private javax.swing.JTextField regiliontxt;
    private javax.swing.JTextField regnotxt;
    private javax.swing.JButton search;
    private javax.swing.JComboBox<String> searchclasstxt;
    public javax.swing.JButton update;
    private javax.swing.JTextField whatsapptxt;
    // End of variables declaration//GEN-END:variables
}