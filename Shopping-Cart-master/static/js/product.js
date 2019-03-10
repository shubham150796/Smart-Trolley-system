var products = {"Apple":1.50,"Orange":2.00,"Strawberry":3.00,"Kiwi":0.75,"Watermelon":6.00,"Grape":0.45,"Lemon":0.90,"Cherry":4.35,"Blueberry":0.75,"Kumquat":1.10,"Pineapple":2.50,"Mango":2.25,"Peach":3.25,"Starfruit":5.00,"Blackberry":1.00}
var saved_invs = [];

function dateinfo() {
  var today = new Date();
  var dd = today.getDate();
  var mm = today.getMonth()+1; //January is 0!
  var yyyy = today.getFullYear();

  if(dd<10) {
      dd='0'+dd
  }

  if(mm<10) {
      mm='0'+mm
  }

  $('#d').attr("placeholder",dd);
  $('#m').attr("placeholder",mm);
  $('#y').attr("placeholder",yyyy);

  $('.inv_date').autotab('number');
}

function fillPrice(productname) {
  var price = products[productname];
}

function productauto() {
  var availableTags;

  availableTags = [
      "Apple",
      "Orange",
      "Strawberry",
      "Kiwi",
      "Watermelon",
      "Grape",
      "Lemon",
      "Cherry",
      "Blueberry",
      "Kumquat",
      "Pineapple",
      "Mango",
      "Peach",
      "Starfruit",
      "Blackberry",
    ];

  $(".productsearch").autocomplete({
      source: availableTags,
      change: function (event, ui) {
        if(!ui.item){
            $(event.target).val("");
        }
        if (ui.item) {
          var name = $(this).val();
          var price = products[name];

          $(this).parent().next().html(price.toFixed(2));
          $(this).parent().next().next().find("input").attr("type", "number");

          updatePrice($(this).parent().next().next().find("input"));
          
          document.getElementById('createbtn').focus();
        }
      }
  });
}

function updatePrice(ele) {
  var price = $(ele).parent().prev().html();
  var quantity = $(ele).val();
  total = price * quantity;
  $(ele).parent().next().html(total.toFixed(2));
  updatetaxandtotal();
}

function newRow() {
  var tableRow = document.getElementById("cloner");
  var tableRowClone = tableRow.cloneNode(true);
  if ($('#beforeInsert').prev().find('.productname').find('input').val() != "") {
    tableRowClone.id = "";
    tableRowClone.style.display = 'table-row';
    var old = parseInt($(tableRowClone).find('.product_order').html(), 10);
    var next = old +1;
    $(tableRow).find('.product_order').html(next);
    $(tableRowClone).find('.product_order').html(next);
    tableRow.parentNode.insertBefore(tableRowClone, document.getElementById("beforeInsert"));
    productauto();
  }
}

function updatetaxandtotal() {
  var total = 0

  $('.producttotal').each(function() {
        total += Number($(this).text());
  });

  var tax = 0.0725 * total;

  $('#tax').html('Tax: $'+tax.toFixed(2));
  total += tax;
  $('#grandtotal').html('<strong>$'+total.toFixed(2)+'</strong>')
}

function saveInv() {
  if ($('#inv_number').val() == "") {
    alert('Invoice Number Is Required!');
    return false;
  } 
  if (saved_invs.indexOf($('#inv_number').val()) != -1) {
    alert('You cannnot save the same invoice twice!');
    return false;
  }

  if (saved_invs.length === 0) {
    document.getElementById('savedWell').style.display = 'block';
    document.getElementById('buffer').style.display = 'none';
    saved_invs.push($('#inv_number').val());
    console.log($('#inv_number').val());
  }
  var svd_inv = document.createElement("li");
  svd_inv.innerHTML = $('#inv_number').val();

  var divider = document.createElement("li");
  divider.setAttribute("class", "divider");

  $(svd_inv).appendTo('#savedWell');
  $(divider).appendTo('#savedWell');
  return false;
}


window.onload = function() {
  dateinfo();
  productauto();
}



